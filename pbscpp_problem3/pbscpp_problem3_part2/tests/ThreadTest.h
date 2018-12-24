#pragma once

#include <thread>
#include <chrono>
#include <future>
#include "IShop.h"
#include <ConcreteProducts.h>

//No need, really, to use heir classes instead of Shop/Product Base.
//But we can, if needed.
//The only difference between Base and Concrete classes is <name> argument in constructor or its lack.

namespace test {

using ShopBasePtr = std::shared_ptr< ShopBase >;
using ProductBasePtr = std::shared_ptr< ProductBase >;

TEST(ThreeShops, OverallTest) {
    std::promise< ShopBasePtr > p_shop1;
    std::promise< ShopBasePtr > p_shop2;
    std::promise< ShopBasePtr > p_shop3;
    std::promise< void > barrier;

    std::thread t([](std::promise< ShopBasePtr >& p_shop1,
					 std::promise< ShopBasePtr >& p_shop2,
					 std::promise< ShopBasePtr >& p_shop3,
					 std::promise< void >& barrier) {
        auto shop1_future = p_shop1.get_future();
        shop1_future.wait();
        ShopBasePtr shop1 = shop1_future.get();

        auto shop2_future = p_shop2.get_future();
        shop2_future.wait();
        ShopBasePtr shop2 = shop2_future.get();

        auto shop3_future = p_shop3.get_future();
        shop3_future.wait();
        ShopBasePtr shop3 = shop3_future.get();

		ProductBasePtr productA = std::make_shared<A>( 1.7);//ALL SHOPS ATTACHED
        productA->StartSales();
        productA->Attach(shop1);
        productA->Attach(shop2);
        productA->Attach(shop3);
        
        ProductBasePtr productB = std::make_shared<B>( 2.3);//NO SHOPS ATTACHED
        productB->StartSales();
        
        ProductBasePtr productC = std::make_shared<C>(13.37);//SHOPS 1 & 3 ATTACHED
        productC->StartSales();
        productC->Attach(shop1);
        productC->Attach(shop3);
        
        ProductBasePtr productD = std::make_shared<D>(220.8);//SHOPS 1 & 2 ATTACHED
        productD->StartSales();
        productD->Attach(shop1);
        productD->Attach(shop2);
        
        productB->Attach(shop2);//attach shops 2 & 3 to B and change price
        productB->Attach(shop3);
        productB->ChangePrice(880.041);
        
        productC->Detach(shop1);//detach shop 1 from C
        productC->ChangePrice(73.31);//change price of C
        
        productD->Detach(shop2);//detach shop 2 from D and change price
        productD->ChangePrice(8.022);

        barrier.set_value();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }, std::ref(p_shop1), std::ref(p_shop2), std::ref(p_shop3), std::ref(barrier));

    ShopBasePtr shop1 = std::make_shared< ShopBase >("shop1");
    ShopBasePtr shop2 = std::make_shared< ShopBase >("shop2");
    ShopBasePtr shop3 = std::make_shared< ShopBase >("shop3");
    p_shop1.set_value(shop1);
    p_shop2.set_value(shop2);
    p_shop3.set_value(shop3);

    for (int i = 0; i < 10; ++i) {
        shop1->Sell("A");
        shop2->Sell("B");
        shop3->Sell("C");
        shop1->Sell("D");
    }

    auto barrier_future = barrier.get_future();
    barrier_future.wait();

	//no changes of A    
    ASSERT_DOUBLE_EQ(1.7, shop1->Sell("A"));
    ASSERT_DOUBLE_EQ(1.7, shop2->Sell("A"));
    ASSERT_DOUBLE_EQ(1.7, shop3->Sell("A"));
    
    //shops 2 & 3 attached to B, B price changed
    ASSERT_DOUBLE_EQ(-1.0, shop1->Sell("B"));
    ASSERT_DOUBLE_EQ(880.041, shop2->Sell("B"));
    ASSERT_DOUBLE_EQ(880.041, shop3->Sell("B"));
    
    //shop 1 detached, price changed
    ASSERT_DOUBLE_EQ(-1.0, shop1->Sell("C"));
    ASSERT_DOUBLE_EQ(-1.0, shop2->Sell("C"));
    ASSERT_DOUBLE_EQ(73.31, shop3->Sell("C"));
    
    //shop 2 detached, price changed
    ASSERT_DOUBLE_EQ(8.022, shop1->Sell("D"));
    ASSERT_DOUBLE_EQ(-1.0, shop2->Sell("D"));
    ASSERT_DOUBLE_EQ(-1.0, shop3->Sell("D"));

    t.join();
}

}
