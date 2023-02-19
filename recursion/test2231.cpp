#include <bits/stdc++.h>
#include "array.h"
using namespace std;

int main()
{
  pair<int, int*> arr = takeInput();

  arrayPrint(arr.second, arr.first);
  
  return 0;
}