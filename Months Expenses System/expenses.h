#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include<map>
#include<unordered_map>
#include<vector>
#include "expenses.h"
using namespace std;

class expenses
{
	struct date {
		int day, month, year;
	};
public:
	string name;
	string category;
	double price, money_spent, money_remaining;
	date buying_date;


	expenses();
	~expenses();
};

