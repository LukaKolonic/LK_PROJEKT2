#include <iostream>
#include "insertion_sort.h"
using namespace std;

int insertion_sort(vector<string> v) {

	int brojac = 0; //FUNK 43

	for (int i = 1; i < v.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (v[j - 1] > v[j]) {
				swap(v[j], v[j - 1]);
				brojac++;
			}
		}
	}
	return brojac;
}


