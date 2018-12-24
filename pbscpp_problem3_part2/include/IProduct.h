#pragma once

#include <memory>
#include <list>
#include <mutex>
#include <atomic>

class IShop;
using IShopPtr = std::shared_ptr< IShop >;
using IShopWeakPtr = std::weak_ptr< IShop >;

class IProduct {
	public:
		virtual ~IProduct() {}
		
		virtual void Attach( IShopWeakPtr AShopWPtr ) = 0;
		virtual void Detach( IShopWeakPtr AShopWPtr ) = 0;
		virtual void StartSales() = 0;
		virtual void StopSales() = 0;
		virtual double GetPrice() const = 0;
		virtual void ChangePrice( double APrice ) = 0;
		virtual std::string GetName() const = 0;
};

class ProductBase : public IProduct, public std::enable_shared_from_this< ProductBase > {
	public:
		ProductBase( std::string AName, double APrice );
		~ProductBase();

		void Attach( IShopWeakPtr AShopWPtr ) override;
		void Detach( IShopWeakPtr AShopWPtr ) override;
		void StartSales() override;
		void StopSales() override;
		void ChangePrice( double APrice ) override;
		double GetPrice() const override;
		std::string GetName() const override;
  
	protected:
		std::atomic<bool> available;
		std::atomic<double> price;
		std::string name;
		mutable std::mutex mutex;
		std::list< IShopWeakPtr > shops;
};
