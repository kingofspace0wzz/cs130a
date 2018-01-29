#include <iostream>
#include <vector>

using namespace std;

bool isSameBST(vector<int> a[], vector<int> b[]){
	if a.size() != b.size() {return false;}
	vector<int> leftA, rightA, leftB, rightB;
	if a.size() == 0 {return true;}
	if a.front() != b.front() {return false;}
	if a.size() == 1 {return true;}

	for (int i = 1; i<a.size(); ++i){
		if (a.at(i) < a.front()) {
			leftA.push_back(a.at(i));
		} else {
			rightA.push_back(a.at(i));
		}
		if (b.at(i) < a.front()){
			leftB.push_back(b.at(i));
		} else {
			rightB.push_back(b.at(i));
		}
	}
	if (leftA.size()!=rightA.size() || leftB.size()!=rightB.size()){
		return false;
	}
	return isSameBST(leftA, leftB) && isSameBST(rightA, rightB);
}

int main(){
	vector<int> a = {7,9,8,1,5};
	vector<int> b = {7,1,9,8,5};

	printf("%s\n", isSameBST(a,b)?"Same BST":"Different BST");

	return 0;

}