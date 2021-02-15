#include "catch.hpp"
#include "beolvasas.h"
#include "csoki.h"

#include <vector>
#include <fstream>

using namespace std;

//#define CHECK_FILE_PARSER
//#define CHECK_INNER
//#define CHECK_OUTER

namespace TestCases
{
    vector<int> k;
    vector<vector<int> > o;

    #ifdef CHECK_FILE_PARSER

    TEST_CASE("Hibas korosztalyok")
    {
        ifstream ifs;

        SECTION("Nemletezo file")
        {
            ifs.open("f0.txt");
            CHECK(!beolv_korosztalyok(k,ifs,false));
            ifs.close();
        }

        SECTION("Rendezetlen file")
        {
            ifs.open("f5.txt");
            CHECK(!beolv_korosztalyok(k,ifs,false));
            ifs.close();
        }
    }

    TEST_CASE("Helyes korosztalyok")
    {
        ifstream ifs;

        SECTION("Ures file")
        {
            ifs.open("f1.txt");
            CHECK(beolv_korosztalyok(k,ifs,false));
            CHECK(k.empty());
            ifs.close();
        }

        SECTION("Stringeket tartalmazo file - utolso ertelmes adatig olvas")
        {
            ifs.open("f3.txt");
            CHECK(beolv_korosztalyok(k,ifs,false));
            CHECK(3 == k.size());
            CHECK(1 == k[0]);
            CHECK(2 == k[1]);
            CHECK(3 == k[2]);
            ifs.close();
        }

        SECTION("Negativ szzamot tartalmazo file - utolso ertelmes adatig olvas")
        {
            ifs.open("f6.txt");
            CHECK(beolv_korosztalyok(k,ifs,false));
            CHECK(k.empty());
            ifs.close();
        }

        SECTION("Atlagos, helyes file")
        {
            ifs.open("f4.txt");
            CHECK(beolv_korosztalyok(k,ifs,false));
            CHECK(4 == k.size());
            CHECK(5 == k[0]);
            CHECK(10 == k[1]);
            CHECK(11 == k[2]);
            CHECK(20 == k[3]);
            ifs.close();
        }
    }

    TEST_CASE("Hibas osztalyzatok")
    {
        ifstream ifs;
        k.clear();

        SECTION("Nemletezo file")
        {
            ifs.open("f0.txt");
            CHECK(!beolv_osztalyzatok(o,k,ifs,false));
            ifs.close();
        }
    }

    TEST_CASE("Helyes osztalyzatok")
    {
        ifstream ifs;

        SECTION("Ures - egy korosztallyal")
        {
            k.clear();
            ifs.open("f1.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(1 == o.size());   //korosztalyok szama, |k|+1 db van mindig
            CHECK(0 == o[0].size());
            ifs.close();
        }

        SECTION("Ures - ket korosztallyal")
        {
            k.push_back(15);
            ifs.open("f1.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(2 == o.size());
            CHECK(0 == o[0].size());
            CHECK(0 == o[1].size());
            ifs.close();
        }

        SECTION("Stringeket tartalmaz - mivel 3 ertelmes szam van benne, egy part olvas be - egy korosztaly")
        {
            k.clear();
            ifs.open("f3.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(1 == o.size());
            CHECK(1 == o[0].size());
            CHECK(2 == o[0][0]);
            ifs.close();
        }

        SECTION("Stringeket tartalmaz - mivel 3 ertelmes szam van benne, egy part olvas be - ket korosztaly, az elsobe kerul")
        {
            k.push_back(1);
            ifs.open("f3.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(2 == o.size());
            CHECK(1 == o[0].size());
            CHECK(0 == o[1].size());
            CHECK(2 == o[0][0]);
            ifs.close();
        }

        SECTION("Stringeket tartalmaz - mivel 3 ertelmes szam van benne, egy part olvas be - ket korosztaly, a masodikba kerul")
        {
            k.clear();
            k.push_back(0);
            ifs.open("f3.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(2 == o.size());
            CHECK(0 == o[0].size());
            CHECK(1 == o[1].size());
            CHECK(2 == o[1][0]);
            ifs.close();
        }

        SECTION("5-nel nagyobb ertekelest tartalmaz tartalmaz - mivel 3 ertelmes szam van benne, egy part olvas be - ket korosztaly, a masodikba kerul")
        {
            k.clear();
            k.push_back(4);
            ifs.open("f5.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(2 == o.size());
            CHECK(0 == o[0].size());
            CHECK(1 == o[1].size());
            CHECK(4 == o[1][0]);
            ifs.close();
        }

        SECTION("Negativ eletkor - mivel 0 ertelmes szam van benne, nulla part olvas be - ket korosztaly")
        {
            k.clear();
            k.push_back(4);
            ifs.open("f6.txt");
            CHECK(beolv_osztalyzatok(o,k,ifs,false));
            CHECK(2 == o.size());
            CHECK(0 == o[0].size());
            CHECK(0 == o[1].size());
            ifs.close();
        }
    }

    #endif // CHECK_FILE_PARSER

    #ifdef CHECK_INNER

     TEST_CASE("Belso fuggveny")
     {
        vector<int> v;

        SECTION("Ures")
        {
            CHECK(0 == osszeg(v));
        }

        SECTION("Egy elem, ami nulla")
        {
            v.clear();
            v.push_back(0);
            CHECK(0 == osszeg(v));
        }

        SECTION("Egy elem, ami nem nulla")
        {
            v.clear();
            v.push_back(2);
            CHECK(2 == osszeg(v));
        }

        SECTION("Tobb elem")
        {
            v.clear();
            v.push_back(2);
            v.push_back(2);
            v.push_back(3);
            v.push_back(5);
            CHECK(12 == osszeg(v));
        }

        SECTION("Tobb elem, nulla osszeg, negativ szamokkal")
        {
            v.clear();
            v.push_back(2);
            v.push_back(2);
            v.push_back(3);
            v.push_back(5);
            v.push_back(-12);
            CHECK(0 == osszeg(v));
        }

        SECTION("Tobb elem, negativ osszeg")
        {
            v.clear();
            v.push_back(2);
            v.push_back(2);
            v.push_back(3);
            v.push_back(5);
            v.push_back(-12);
            v.push_back(-5);
            CHECK(-5 == osszeg(v));
        }
     }

    #endif // CHECK_INNER

    #ifdef CHECK_OUTER

    TEST_CASE("Kulso fuggveny")
     {
        vector<vector<int> > v;

        SECTION("Ures")
        {
            CHECK(optlinker(v));
        }

        SECTION("Egy elem, ami ures, igy igaz ra")
        {
            v.clear();
            vector<int> v1;
            v.push_back(v1);
            CHECK(optlinker(v));
        }

        SECTION("Egy elem, amire igaz")
        {
            v.clear();
            vector<int> v1;
            v1.push_back(4);
            v.push_back(v1);
            CHECK(optlinker(v));
        }

        SECTION("Egy elem, amire nem igaz")
        {
            v.clear();
            vector<int> v1;
            v1.push_back(3);
            v.push_back(v1);
            CHECK(!optlinker(v));
        }

        SECTION("Ket elem, igaz")
        {
            v.clear();
            vector<int> v1;
            v1.push_back(5);
            v1.push_back(4);
            vector<int> v2;
            v1.push_back(5);
            v1.push_back(3);
            v.push_back(v2);
            CHECK(optlinker(v));
        }

        SECTION("Harom elem, a legvegen romlik el")
        {
            v.clear();
            vector<int> v1;
            v1.push_back(5);
            v1.push_back(4);
            vector<int> v2;
            v1.push_back(5);
            v1.push_back(3);
            vector<int> v3;
            v1.push_back(4);
            v1.push_back(3);
            v.push_back(v3);
            CHECK(optlinker(v));
        }
     }

    #endif // CHECK_OUTER

}
