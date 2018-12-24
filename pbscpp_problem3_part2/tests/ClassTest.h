#pragma once

#include "IProduct.h"
#include "IShop.h"

//No need, really, to use heir classes instead of Shop/Product Base.
//But we can, if needed.
//The only difference between Base and Concrete classes is <name> in constructor or its lack.

namespace test {

TEST(ProductTest, PriceChangeTest) {
    ProductBase product("product", 1.7);

    ASSERT_DOUBLE_EQ(1.7, product.GetPrice());

    product.ChangePrice(2.3);

    ASSERT_DOUBLE_EQ(2.3, product.GetPrice());
}

TEST(ProductTest, ShopSellTest) {
    std::shared_ptr< ProductBase > product = std::make_shared< ProductBase >("product", 1.7);
    std::shared_ptr< ShopBase > shop = std::make_shared< ShopBase >("shop");

    product->Attach(shop);
    product->StartSales();
    product->ChangePrice(3.6);
    
    ASSERT_DOUBLE_EQ(3.6, shop->Sell("product"));
    
    product->ChangePrice(2.7);
    
    ASSERT_DOUBLE_EQ(2.7, shop->Sell("product"));
}

TEST(ProductTest, DetachNSalesTest ) {
    std::shared_ptr< ProductBase > product = std::make_shared< ProductBase >("product", 1.7);
    std::shared_ptr< ShopBase > shop1 = std::make_shared< ShopBase >("shop1");
    std::shared_ptr< ShopBase > shop2 = std::make_shared< ShopBase >("shop2");
    
    product->Attach(shop1);
    product->Attach(shop2);
    product->StartSales();
    
    ASSERT_DOUBLE_EQ(1.7, shop1->Sell("product"));
    ASSERT_DOUBLE_EQ(1.7, shop2->Sell("product"));
    
    product->Detach(shop2);
    
    ASSERT_DOUBLE_EQ(1.7, shop1->Sell("product"));
    ASSERT_DOUBLE_EQ(-1.0, shop2->Sell("product"));
    
    product->StopSales();
    
    ASSERT_DOUBLE_EQ(-1.0, shop1->Sell("product"));
    ASSERT_DOUBLE_EQ(-1.0, shop2->Sell("product"));
}

}
