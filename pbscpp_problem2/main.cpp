#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <limits>

using namespace std;
using dIter = vector< double >::const_iterator;

//CLASS HIERARCHY

class TRandomNumberGenerator {
public:
    virtual ~TRandomNumberGenerator() = default;
    virtual double Generate() = 0;
};

class TPoissonRand : public TRandomNumberGenerator {
    poisson_distribution< int > distr;
    default_random_engine gen;

public:
    TPoissonRand( double L ) {
        distr = poisson_distribution< int >( L );
    }
    double Generate() override {
        return distr( gen );
    }
private:
};

class TBernoulliRand : public TRandomNumberGenerator {
    bernoulli_distribution distr;
    default_random_engine gen;

public:
    TBernoulliRand( double p ) {
        distr = bernoulli_distribution( p );
    }
    double Generate() override {
        if( distr( gen ) )
            return 1.0;//TRUE
        else
            return -1.0;//FALSE
    }
};

class TGeomRand : public TRandomNumberGenerator {
    geometric_distribution< int > distr;
    default_random_engine gen;

public:
    TGeomRand( double p ) {
        distr = geometric_distribution< int >( p );
    }
    double Generate() override {
        return distr( gen );
    }
};

class TFiniteDiscrVarRand : public TRandomNumberGenerator {
    discrete_distribution< int > distr;
    vector< double > X;
    default_random_engine gen;

public:
    TFiniteDiscrVarRand( const vector< double >& vals, const vector< double >& probs )  {
        distr = discrete_distribution< int >( probs.cbegin(), probs.cend() );
        X = vector< double >( vals.cbegin(), vals.cend() );
    }
    double Generate() override {
        return X[ distr( gen ) ];
    }
};

//---------------------------------------------------------------------------------------------------------------------
//FACTORY METHOD
//Возможно, можно сделать проще, но не вышло,
//а через класс-фабрику делать муторно.

template< class TDummy, typename ...TArgs >
unique_ptr< TRandomNumberGenerator > CreateConcrete( const TArgs&... ) { return nullptr; }


template<>
unique_ptr< TRandomNumberGenerator > CreateConcrete< TPoissonRand >( const double& L ) {
    //lambda has to be greater than zero
    if ( L <= 0 ) {
        return nullptr;
    }
    else
        return make_unique< TPoissonRand >( L );
}


template<>
unique_ptr< TRandomNumberGenerator > CreateConcrete< TBernoulliRand >( const double& p ) {
    //p has to be in [0 ; 1]
    if ( p < 0.0 || p > 1.0 ) {
        return nullptr;
    }
    else
        return make_unique< TBernoulliRand >( p );
}

template<>
unique_ptr< TRandomNumberGenerator > CreateConcrete< TGeomRand >( const double& p ) {
    //p has to be in [0 ; 1]
    if ( p < 0.0 || p > 1.0  ) {
        return nullptr;
    }
    else
        return make_unique< TGeomRand >( p );
}


template<>
unique_ptr< TRandomNumberGenerator > CreateConcrete< TFiniteDiscrVarRand >( const vector< double >& vals, const vector< double >& probs ) {
    //obviously has to be equal sized
    if ( vals.size() != probs.size() ) {
        return nullptr;
    }

    //sum of all probabilities
    double probsum = 0;
    for ( auto p: probs ) {
        probsum += p;
    }

    //probability sum != 1 => NULLPTR
    if ( abs( 1.0 - probsum ) >= numeric_limits< double >::epsilon() ) {
        return nullptr;
    }
    else
        return make_unique< TFiniteDiscrVarRand >( vals, probs );
}


template<typename ...TArgs>
unique_ptr< TRandomNumberGenerator > CreateRand( const string& type, TArgs ... args ) {
    if ( type == "poisson" ) {
        return CreateConcrete< TPoissonRand >( args... );
    } else
        if (type == "bernoulli") {
            return CreateConcrete< TBernoulliRand >( args... );
        }
            else if (type == "geometric") {
                return CreateConcrete< TGeomRand >( args... );
            } else
                if (type == "finite") {
                    return CreateConcrete< TFiniteDiscrVarRand >( args... );
                } else
                    return nullptr;
}

//---------------------------------------------------------------------------------------------------------------------
//TESTS

bool TestPoisson( double L, size_t iters = 1000 ) {
    unique_ptr< TRandomNumberGenerator > randUPtr = CreateRand( "poisson", L );
    if ( !randUPtr )
        return false;

    //compute experimental mean
    double expMean = 0;
    for( size_t i = 0; i < iters; i++ )
        expMean += randUPtr->Generate();
    expMean /= iters;

    double maxdif = L > 10 ? L / 100 : 0.1;
    cout << "POISSON Lambda: " << L << " Theor: " << L << " Exp: " << expMean << " maxdif: " << maxdif << endl;
    return abs( L - expMean ) < maxdif;
}


bool TestBernoulli( double p, size_t iters = 1000 ) {
    unique_ptr< TRandomNumberGenerator > randUPtr = CreateRand( "bernoulli", p );
    if ( !randUPtr )
        return false;

    double trueCount = 0;
    for (size_t i = 0; i < iters; i++) {
        if( randUPtr->Generate() > 0 )
            trueCount += 1;
    }
    double res = trueCount / iters;

    cout << "BERNOULLI p: " << p << " Exp: " << res << " maxdif: 0.1 " << endl;
    return abs( p - res ) < 0.1;
}



bool TestGeom( double p, size_t iters = 1000 ) {
    unique_ptr< TRandomNumberGenerator > randUPtr = CreateRand( "geometric" , p );
    if ( !randUPtr )
        return false;

    double expMean = 0, theorMean = p > numeric_limits< double >::epsilon() ? (1 - p) / p : -1.0;
    for( size_t i = 0; i < iters; i++ )
        expMean += randUPtr->Generate();
    expMean /= iters;

    if( theorMean < 0 ) {
        cout << "GEOM p: " << p << " Theor: +INF Exp: " << expMean << " How to even count this?" << endl;
        return true;
    }
    else {
        cout << "GEOM p: " << p << " Theor: " << theorMean << " Exp: " << expMean << " maxdif: 0.1 " << endl;
        return abs(theorMean - expMean) < 0.1;
    }
}



bool TestFiniteDiscrVar(const vector<double>& vals, const vector<double>& probs, size_t iters = 1000) {
    unique_ptr< TRandomNumberGenerator > randUPtr = CreateRand( "finite", vals, probs );
    if ( !randUPtr ) {
        cerr << "Error creating finite generator" << endl;
        return false;
    }

    double theorMean = 0;
    for ( size_t i = 0; i < vals.size(); i++ ) {
        theorMean += vals[i] * probs[i];
    }

    double expMean = 0;
    for (size_t i = 0; i < iters; i++) {
        expMean += randUPtr->Generate();
    }
    expMean /= iters;

    double maxdif = theorMean > 10 ? theorMean / 100 : 0.1;
    cout << "FINITE Theor: " << theorMean << " Exp: " << expMean << " maxdif: " << maxdif << endl;
    return abs( expMean - theorMean ) < maxdif;
}

//---------------------------------------------------------------------------------------------------------------------
//MAIN

int main(int argc, char** argv) {
    //в итоге лучше всего проверять визуально
    cout << TestPoisson( 0.5 ) << endl;
    cout << TestPoisson( 0.3 ) << endl;
    cout << TestPoisson( 0.11) << endl;
    cout << TestPoisson( 10 ) << endl;
    cout << TestPoisson( 25 ) << endl;
    cout << TestPoisson( 100 ) << endl;

    cout << TestBernoulli( 0.5 ) << endl;
    cout << TestBernoulli( 0.25 ) << endl;
    cout << TestBernoulli( 0.3 ) << endl;
    cout << TestBernoulli( 0.7325 ) << endl;
    cout << TestBernoulli( 0.0 ) << endl;
    cout << TestBernoulli( 1.0 ) << endl;

    cout << TestGeom( 0.5 ) << endl;
    cout << TestGeom( 0.25 ) << endl;
    cout << TestGeom( 0.3 ) << endl;
    cout << TestGeom( 0.7235 ) << endl;
    cout << TestGeom( 0.0 ) << endl;
    cout << TestGeom( 1.0 ) << endl;

    cout << TestFiniteDiscrVar( {1.0, 2.0, 3.0, 4.0}, {0.4, 0.3, 0.2, 0.1} ) << endl;
    cout << TestFiniteDiscrVar( {10.0, 20.0, 30.0, 40.0}, {0.4, 0.3, 0.2, 0.1} ) << endl;
    cout << TestFiniteDiscrVar( {1.0, 3.0, 3.0, 3.0}, {0.4, 0.2, 0.2, 0.2} ) << endl;
    cout << TestFiniteDiscrVar( {1.0, 2.0, 2.0, 5.0}, {0.5, 0.2, 0.2, 0.1} ) << endl;

    return 0;
}