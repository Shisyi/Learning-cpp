
#include <iostream>
#include <vector>

using namespace std;

const int num_2_negative = 5;

int bin_search(const vector<int>& mem, const int target_number) {
	int tmp{};
	int idx{};
	int half{};

	//while (tmp != target_number) {
	idx = mem.size() / 2;
	half = idx;

	while (1) {
		if (half != 1) {
			half = (half) / 2;
		}
		else {
			half = 1;
		}

		cout << "half : " << half << endl;
		tmp = mem[idx];
		cout << "idx : " << idx << endl;
		cout << "tmpx : " << tmp << endl;
		if (tmp > target_number)
		{
			cout << " > " << endl;
			idx = idx - half;
		}
		else if (tmp < target_number) {
			idx = idx + half;
			cout << " < " << endl;
		}
		else {
			cout << "\n Index of target number : " << idx << " " << endl;
			break;
		}
	}
	return(idx);
}

vector<int> bubble_sort(vector<int>& mem) {
	int cnt = 1;
	int tmp{};
	while (cnt > 0) {
		cnt = 0;
		for (int i = 0; i < mem.size()-1; i++) {
			if (mem[i] > mem[i + 1]) {
				tmp = mem[i];
				mem[i] = mem[i + 1];
				mem[i + 1] = tmp;
				cnt++;

			}
		}
	};
	return mem;
}

int main()
{	
	int array_size{};
	int target_number{};
	cout << "Please write memory size more then 0" << " : ";
	cin >> array_size;
	cout << "\n";

	cout << "Please write the number to find from " << -num_2_negative << " to " << array_size - num_2_negative - 1 << " : ";
	cin >> target_number;
	cout << "\n";

	vector<int> mem(array_size);
	
	cout << "Elements of memory : ";
	for (int i = 0; i < array_size; i++) {
		//mem[i] = i - num_2_negative;
		mem[i] = -(4*i - num_2_negative) % 7;
		cout << mem[i] << " ";
	}
	cout << endl << endl;

	bubble_sort(mem);
	cout << "Elements of memory sorted : ";
	for (int i = 0; i < array_size; i++) {
		cout << mem[i] << " ";
	}
	cout << "\n" << "\n";

	return bin_search(mem,target_number);

};

