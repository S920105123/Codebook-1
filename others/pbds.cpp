#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
namespace __gnu_pbds{
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
}

int main() {
	__gnu_pbds::ordered_set S;
	S.insert(5);
	S.insert(7);
	S.insert(10);
	cout << S.order_of_key(4) << '\n'; // How many smaller
	cout << S.order_of_key(5) << '\n';
	cout << S.order_of_key(6) << '\n';
	cout << *S.find_by_order(0) << '\n';
	cout << *S.find_by_order(2) << '\n';
	return 0;
}
