#include "IShop.h"
#include "IProduct.h"

ShopBase::ShopBase( std::string AName)
		: name( AName )
	{}

void ShopBase::AddProduct( IProductPtr AProductShdPtr ) {
	if(AProductShdPtr == nullptr)
		return;
	std::lock_guard< std::mutex > lock( mutex );
	auto it = products.find( AProductShdPtr->GetName() );
	if ( it == products.end() ) 
		products.emplace( AProductShdPtr->GetName(), AProductShdPtr );
}

void ShopBase::RemoveProduct( std::string AName ) {
	std::lock_guard< std::mutex > lock( mutex );
	products.erase( AName );
}

double ShopBase::Sell( std::string AName ) const {
	std::lock_guard< std::mutex > lock( mutex );
	auto it = products.find( AName );
	if ( it == products.end() ) 
	  return -1.0;

	return (it->second).lock()->GetPrice();//it -> weakptr -> shdptr -> price
}
