#pragma once
#include "Account.h"

// base class 의 포인터나 레퍼런스로 child class 를 가리킬 수 있다
void Transact(Account* pAccount);
void Transact(Account& pAccount);
