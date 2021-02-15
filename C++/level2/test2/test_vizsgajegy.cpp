#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <iostream>
#include "seqinfile.h"

using namespace std;

int process(const Student &e);

TEST_CASE("ures fajl", "[t0.txt]")
{
    SeqInFile t("t0.txt");
    for(t.first(); !t.end(); t.next() ){
        CHECK(1==2);
    }
}

TEST_CASE("Elfogadna, de nem tudja", "[t1.txt]")
{
    SeqInFile t("t1.txt");
    for(t.first(); !t.end(); t.next() ){
        CHECK(process(t.current())==-1);
    }
}

TEST_CASE("Beszamitana, de nem tudja", "[t2.txt]")
{
    SeqInFile t("t2.txt");
    for(t.first(); !t.end(); t.next() ){
        CHECK(process(t.current())==-2);
    }
}

TEST_CASE("Elfogadja", "[t3.txt]")
{
    SeqInFile t("t3.txt");
    for(t.first(); !t.end(); t.next() ){
        CHECK(process(t.current())==4);
    }
}

TEST_CASE("Beszamitja", "[t4.txt]")
{
    SeqInFile t("t4.txt");
    t.first();
    CHECK(process(t.current())==3);

    t.next();
    CHECK(process(t.current())==2);
}

TEST_CASE("Csak a vizsga", "[t5.txt]")
{
    SeqInFile t("t5.txt");
    t.first();
    CHECK(process(t.current())==3);

    t.next();
    CHECK(process(t.current())==2);

    t.next();
    CHECK(process(t.current())==1);
}

int process(const Student &e)
{
    int test = e.test1+e.test2;
    if(e.accept && (test<40 || e.exam>0)) return -1;
    else if(e.include && e.exam>30) return -2;
    else{
        int point = 0;

        if(e.accept && test>=40){
            point = test;
        }else if((!e.accept || test<40) && e.include){
            point = test/2 + e.exam/2;
        }else if((!e.accept || test<40) && !e.include){
            point = e.exam;
        }
        return point/10;
    }
}


