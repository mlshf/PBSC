#pragma once

#include <memory>
#include <mutex>
#include <map>

class IProduct;
using IProductPtr = std::shared_ptr< IProduct >;
using IProductWeakPtr = std::weak_ptr< IProduct >;

class IShop {
public:
	virtual ~IShop() {}

    virtual void AddProduct( IProductPtr AProductShdPtr ) = 0;
    virtual void RemoveProduct( std::string AName ) = 0;
    virtual double Sell( std::string AName ) const = 0;
};

class ShopBase : public IShop, public std::enable_shared_from_this< ShopBase > {
 public:
  ShopBase( std::string AName );
  
  void AddProduct( IProductPtr AProductShdPtr ) override;
  void RemoveProduct( std::string AName ) override;
  double Sell( std::string AName ) const override;

protected:
    std::string name;
    mutable std::mutex mutex;
	std::map< std::string, IProductWeakPtr > products;//name - product
};
