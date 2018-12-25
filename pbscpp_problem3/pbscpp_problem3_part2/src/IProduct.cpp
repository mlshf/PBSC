#include "IProduct.h"
#include "IShop.h"

ProductBase::ProductBase( std::string AName, double APrice ) : 
		name( AName ), 
		price( APrice ), 
		available( false ) 
	{}

ProductBase::~ProductBase() { StopSales(); }

double ProductBase::GetPrice() const { return price; }

std::string ProductBase::GetName() const { return name; }

void ProductBase::ChangePrice( double APrice ) {
	std::lock_guard<std::mutex> lock( mutex );
    price = APrice;
}

void ProductBase::Attach( IShopWeakPtr AShopWPtr ) {
	
	auto shop_shdptr = AShopWPtr.lock();

	if ( shop_shdptr ) {
		shops.push_back( shop_shdptr );
		if( available )
			shop_shdptr->AddProduct( shared_from_this() );
	}
}

void ProductBase::Detach( IShopWeakPtr AShopWPtr ) {
	auto shop_shdptr = AShopWPtr.lock();

	if ( shop_shdptr ) {//shop not expired
		shops.remove_if( 
			[ & ]( const IShopWeakPtr& shop_wptr ) {
				auto lptr = shop_wptr.lock();
				if (!lptr) return true;
				return lptr == shop_shdptr;
			}
		);
		if( available )
			shop_shdptr->RemoveProduct( name );
	}
}

void ProductBase::StartSales() {
	available = true;//было непонятно, должен ли продукт начинать продажу
	//если продажи уже были до этого остановлены. Если Не должен, то перед первой строчкой должно быть:
	//if( stopped ) return; - где stopped ещё один флаг в product.
	for (IShopWeakPtr& shop_wptr : shops) {
		auto shop_shdptr = shop_wptr.lock();
		if ( shop_shdptr ) {
			shop_shdptr->AddProduct( shared_from_this() );
		}
	}
}

void ProductBase::StopSales() {
	available = false;
	for (IShopWeakPtr& shop_wptr : shops) {
		auto shop_shdptr = shop_wptr.lock();
		if ( shop_shdptr ) {
			shop_shdptr->RemoveProduct( name );
		}
	}
}
