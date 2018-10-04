#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <vector>
#include <assert.h>

struct TItem {
    int value;
    time_t timestamp;
    TItem(int v)
            : value(v)
            , timestamp(std::time(0)) {}
// ...
};
using Items = std::vector<TItem>;
using namespace std;

//pt.1
template <int... Args>
Items MakeItemsSimple()
{
    Items result;
    for( auto arg: {Args...} )
        result.push_back( arg );
    return result;
};

//pt.2
//defining operator needed in std::find
bool operator==( const TItem& AItem, const int& AValue )
{
    return AItem.value == AValue;
}

//using std::find and == operator defined above
auto MakePredicate( Items& AItems )
{
    auto result_find = [&](int value) -> bool{
        return find( AItems.begin(), AItems.end(), value ) != AItems.end();
    };

    return result_find;
}

//alternative w/ recursive lambda
auto MakePredicate_recursive( Items& AItems )
{
    function<bool(int)> result_recursive = [&](int value) -> bool{
        if(AItems[0].value == value)
            return true;
        else
        if( AItems.size() > 1 ){
            TItem tmpItem( AItems[ 0 ] );
            AItems.erase( AItems.begin() );
            bool inner_result = result_recursive( value );
            AItems.insert( AItems.begin(), tmpItem );
            return inner_result;
        } else
            return false;
    };

    return result_recursive;
}

//check data vizually =)
void Display( Items& AItems )
{
    for( auto item: AItems)
        cout << item.value << endl;
    cout << endl;
}

int main()
{
    //pt.1 variadic
    Items items = MakeItemsSimple<0, 1, 4, 5, 6>();
    Items newItems = MakeItemsSimple<7, 15, 1>();

    //check compliance with data given
    Display( items );
    Display( newItems );

    //pt.2 lambda-object
    auto isFound = MakePredicate(items);
    auto isFoundNew = MakePredicate(newItems);
    //recursive alternative
    auto isFound_recursive = MakePredicate_recursive(items);
    auto isFoundNew_recursive = MakePredicate_recursive(newItems);

    //for normal people
    assert(isFound(0) == true);
    assert(isFound(7) == false);
    assert(isFoundNew(7) == true);
    assert(isFoundNew(6) == false);

    //for recursive people
    assert(isFound_recursive(0) == true);
    assert(isFound_recursive(7) == false);
    assert(isFoundNew_recursive(7) == true);
    assert(isFoundNew_recursive(6) == false);

    //check compliance with data given
    Display( items );
    Display( newItems );

    return 0;
}