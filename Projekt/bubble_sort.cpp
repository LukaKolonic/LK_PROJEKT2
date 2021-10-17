#include <iostream>
#include "bubble_sort.h"
using namespace std;

int bubble_sort(vector<string> v) {

	int brojac = 0; //FUNK 43

	bool sortirano;
	for (int i = 0; i < v.size() - 1; i++) {
		sortirano = true;
		for (int j = 0; j < v.size() - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				brojac++;
				sortirano = false;
			}
		}

		if (sortirano) {
			break;
		}
	}
	return brojac;
}

