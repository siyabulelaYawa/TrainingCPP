
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <random>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;

struct Values {
	
public:
	int val;
	string str;
	Values(int a,string Str) : val(a), str(Str) {}
	Values(): val(-1),str("-1"){}
	void display() {
		cout << "int: " << val << " string: " << str << endl;
	}
	/*
	ostream& operator<<(ostream& out) {
		out << "int: " << val << " string: " << str;
		return out;
	}
	*/
};
//template<class T>
void display(vector<int> vect) {

	for (int a : vect) {
		cout << a  << " ";
	}
	cout << endl;
}

void vectors() {
	//-------------------------------------------------------VECTORS------------------------------------------------

	//----------sorting---------

	//Using ints
	vector<int> lis = { 11,2,3,4,7,8,1,15,3,11,10 };  //vector;

	cout << "original list" << endl;
	for (auto val : lis) {
		cout << val << " ";
	}
	cout << endl;
	sort(lis.begin(), lis.end(), [](int x, int y) { return x < y; });
	cout << "-----------------Sorting integers----------------------------------------" << endl;
	for (auto val : lis) {
		cout << val << " ";
	}
	cout << endl;
	//Using structs
	Values a(5, "c");
	Values b(3, "b");
	Values c(10, "a");
	cout << "-------------------Sorting struct on int value ascending order---------------" << endl;
	vector < Values > liz = { a,b,c };
	sort(liz.begin(), liz.end(), [](Values v1, Values v2) {return v1.val < v2.val; });

	for (auto valz : liz) {
		valz.display();
	}
	cout << endl;

	cout << "--------------------Sorting struct on string value in decending order----------" << endl;
	sort(liz.begin(), liz.end(), [](Values v1, Values v2) {return v1.str > v2.str; });

	for (auto valz : liz) {
		valz.display();
	}

	cout << endl;
}

void filtering() {
	vector<int> lis = { 11,2,3,4,7,8,1,15,3,11,10 };  //vector;

	Values a(5, "c");
	Values b(3, "b");
	Values c(10, "a");
	cout << "-------------------Sorting struct on int value ascending order---------------" << endl;
	vector < Values > liz = { a,b,c };

	vector<int> lisCopy;

	cout << "copy all even numbers from lis vector to lisCopy vector display using FOR_EACH" << endl;
	copy_if(lis.begin(), lis.end(), back_inserter(lisCopy), [](int x) {return (x % 2 == 0); });

	for_each(lisCopy.begin(), lisCopy.end(), [](int x) { cout << x << " "; });

	int sum = 0;
	for_each(lis.begin(), lis.end(), [&](int x) {sum += x; });

	cout <<"sum vector using foreach :) "<< endl;
	cout << sum << endl;

}
void transforms() {
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,11,10 };  //vector;
	vector<int> ints2 = { 11,2,3,4,7,8,1,15,3,11,10 };
	vector<int> ints3(ints.size());
	transform(ints.begin(), ints.end(), ints2.begin(),  ints3.begin(), [](int a, int b) {return a + b; });

	vector<string> strings = { "a","b","c","d","e","f","g","h","i","j","k" };
	vector<Values> structValues(ints.size());

	transform(ints.begin(), ints.end(), strings.begin(),  structValues.begin(),
		[structValues](int intsV, string stringsV) {
			Values a(intsV, stringsV);
			return a;
		});

	for_each(structValues.begin(), structValues.end(), [](Values v1) {v1.display(); });
	

}

void extra() {
	int a = 5;
	int b = 1;

	(a > b) ? cout << a: cout << b;

	//try fibunacci numbers lambda
	vector<int> ints;
	std::function<int(int)> Fib = [&Fib, &ints](int n) {
		
		if (n == 0) {
			return n;

		}
		else if (n == 1) {
			return n;
		}
		else {
			
			int s=(Fib(n - 1) + Fib(n - 2));	
			ints.push_back(s);
			return s;
		}
	};
	cout << Fib(6) << endl;
}
void binary_searching() {
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,11,10 };
	int val = 1;
	bool found = binary_search(ints.begin(), ints.end(), val);
	(found) ? cout << val << " FOUND"<<endl : cout << val << " NOT FOUND"<<endl;

	//now sort the list

	sort(ints.begin(), ints.end());
	cout << "After Sorting" << endl;
	found = binary_search(ints.begin(), ints.end(), val);
	(found) ? cout << val << " FOUND" <<endl: cout << val << " NOT FOUND"<<endl;

}
void heaps() {
	//The heap data manipulates the list but does not remove or add things to it, it is only for modifying 
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,11,10 };

	//always call push heap after inserting a new value or the property might get lost
	make_heap(ints.begin(), ints.end());  //makes the vector a max heap
	//first example here pushing 100
	ints.push_back(100);
	push_heap(ints.begin(), ints.end());

	//then again here after push 5
	ints.push_back(5);
	push_heap(ints.begin(), ints.end());

	//remove the value at the top (max value in this case)

	pop_heap(ints.begin(), ints.end());  //moves the value at the front of the list to the end of the list
	ints.pop_back();

	sort_heap(ints.begin(), ints.end());  //sorts the vector in ascending order and it does not become a heap anymore
	(is_heap(ints.begin(), ints.end()))? cout<<"YES"<<endl : cout<<"NO"<<endl;    //check if container is still a heap

	make_heap(ints.begin(), ints.end());  //So make it a heap again
	cout << "After making it a heap again" << endl;
	(is_heap(ints.begin(), ints.end())) ? cout << "YES" << endl : cout << "NO" << endl;    //check if container is still a heap
	
	vector<int>::iterator endOfHeap = is_heap_until(ints.begin(), ints.end());  //points to the end of the part which is a heap

	for (int i : ints) {
		cout << i << " " << endl;
	}
}
void sorts() {
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,11,10 };  //vector;
	vector<int> ints2;

	for (int i = 0; i < 10; i++) ints2.push_back(i);
	//partial_sort(ints.begin(), ints.begin() + 3, ints.end(), [](int x, int y) {return x < y; });  //partial_sort(begining of list, num of items, end of portion being considered for sorting.
	cout << "Using partial sort" << endl;
	for (int i : ints) {
		cout << i << " ";
	}
	//nth-element  for small lists this algorithm sorts the whole list but for larger lists applies the quick select algorithm
	cout << endl;
	random_shuffle(ints2.begin(), ints2.end());
	for (int i : ints) {
		cout << i << " ";
	}
	nth_element(ints2.begin(), ints2.begin()+5, ints2.end());
	cout << endl;
	cout << "using n_th element" << endl;
	for (int i : ints2) {
		cout << i << " ";
	}


	//sort_heap is covered in heaps()
	std::inplace_merge(ints.begin(), ints.begin() + 5, ints.end());  //uses merge sort

	for (int i : ints) {
		cout << i << " ";
	}

}

void partitions() {
	//sort the collection with regards to some boolean value (predicate) 
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,11,10 }; 
	partition(ints.begin(), ints.end(), [](int x) {return x % 2 == 0; });  //partition even and odd numbers 
	for (int i : ints) {
		cout << i << " ";
	}
	vector<int>::iterator middle = partition_point(ints.begin(), ints.end(), [](int x) {return x % 2 == 0; });
	cout << endl;
	cout << *middle << endl;
}
void other_permutations() {
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,13,10 };

	cout << "Rotate moves a value pointed to to the biginning of the container" << endl;
	rotate(ints.begin(), ints.end()-2,ints.end());
	for (int i : ints) {
		cout << i << " ";
	}
	std::random_device rd;
	cout << endl;
	cout << "Shuffle vector" << endl;
	shuffle(ints.begin(), ints.end(),rd);
	for (int i : ints) {
		cout << i << " ";
	}

	cout << endl;

	
	for (int i = 0; i < ints.size(); i++) {
		display(ints);
		next_permutation(ints.begin(), ints.end());  //rotates the list forming all possible combinations
		//prev_permutation(ints.begin(), ints.end());
	}
	cout << endl;
	sort(ints.begin(), ints.end());
	cout << "reverse vector" << endl;
	reverse(ints.begin(), ints.end());
	for (int i : ints) {
		cout << i << " ";
	}
}
void partitioning_sort_heap() {
	//stable keeps the order after performing sorting or partitioning
	vector<int> ints = { 11,2,3,4,7,8,1,15,3,13,10 };
	/*Sorts the elements in the range [first,last) 
	into ascending order, like sort, but stable_sort preserves the relative order of the elements with equivalent values.*/
	stable_sort(ints.begin(), ints.end());
	for (int i : ints) {
		cout << i << " ";
	}
	cout << endl;
	stable_partition(ints.begin(), ints.end(), [](int x) {return x % 2 == 0; });
	for (int i : ints) {
		cout << i << " ";
	}

	//function to check if container is sorted,partitioned or heap respectively
	is_sorted(ints.begin(), ints.end());
	is_partitioned(ints.begin(), ints.end(), [](int x) {return x % 2 == 0; });
	is_heap(ints.begin(), ints.end());

	////function that get a pointer to the first element of a container is where it is unsorted,unpartitioned or not a heap
	is_sorted_until(ints.begin(), ints.end());
	//is_partitioned_until(ints.begin(), ints.end(), [](int x) {return x % 2 == 0; });
	is_heap_until(ints.begin(), ints.end());


}
void numericAlgorithms() {

	vector<int> ints = { 11,2,3,4,7,8,1,15,3,13,10,3 };
	vector<int> ints2(10);
	generate(ints2.begin(), ints2.end(), []() {return rand() % 100; });
	for_each(ints2.begin(), ints2.end(), [](int x) {cout << x << " "; });
	int i = 3;
	int counter=count(ints.begin(), ints.end(), 3);
	cout << "number of " << i << "'s is " << counter<<endl;
	 
	int sum =accumulate(ints.begin(), ints.end(),0);
	cout << "sum is: "<< sum << endl;

	int prod = accumulate(ints.begin(), ints.end(), 1,std::multiplies<int>());
	cout << "product is: " << prod << endl;

	partial_sum(ints.begin(), ints.end(), ints.begin()); //sums up values 0 (1+0) (1+1) (2+1) ...
	partial_sum(ints.begin(), ints.end(), ints.begin(), [](int x1, int x2) {return x1-x2; }); //uses a function instead 
	display(ints);

	vector<int>::iterator ptr = find_if(ints.begin(), ints.end(), [](int x) {return x == 3; });

	if (ptr != ints.end()) {
		cout << "-------" << endl;
		cout << *ptr << endl;
	}
	ints2 = { 11,2,3,4,7,8,1,15,3,13,10,3 };
	int innprod=std::inner_product(ints.begin(), ints.end(), ints2.begin(), 0);
	cout << "inner product: " << innprod;

	int r2 = std::inner_product(ints.begin(), ints.end(), ints2.begin(), 0,
		std::plus<>(), std::equal_to<>());
	std::cout << "Number of pairwise matches between a and b: " << r2 << '\n';

	vector<int> temp(ints.size());
	adjacent_difference(ints.begin(), ints.end(), temp.begin());

	display(temp);
	std::string in = "abcdefgh", out;
	/*
	std::sample(in.begin(), in.end(), std::back_inserter(out),
		5, std::mt19937{ std::random_device{}() });
	std::cout << "five random letters out of " << in << " : " << out << '\n';
	*/

	cout << "All of checks if all values in the collection satisfy the predicate" << endl;
	int devisor = 2;
	(all_of(ints.begin(), ints.end(), [=](int x) {return x % devisor == 0; })) ? cout << "all divisable by " << devisor << endl : cout << "Atleast one NOT devisible " <<"by "<<devisor <<endl;
	(any_of(ints.begin(), ints.end(), [=](int x) {return x % devisor == 0; })) ? cout << "atleast one divisable by " << devisor << endl : cout << "None are devisible " << "by " << devisor << endl;
	(any_of(ints.begin(), ints.end(), [=](int x) {return x % devisor == 0; })) ? cout << "Atleast one NOT devisible " << devisor << endl : cout << " " << "all are divisable by " << devisor << endl;



}

int main() {
	//vectors();
	//filtering();
	//transforms();
	//extra();
	//binary_searching();
	//heaps();
	//sorts();
	//partitions();
	//other_permutations();
	//partitioning_sort_heap();
	numericAlgorithms();

	return 0;

}


