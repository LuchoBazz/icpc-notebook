#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename K, typename V, typename Comp = less<K>>
using indexed_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = less<K>>
using indexed_set = indexed_map<K, null_type, Comp>;
// Usage
//    auto it = any.find_by_order(idx); (0-indexed)
//    (*it).first, (*it).second
//    int index = any.order_of_key(key);
//    {1: 10, 2 :20,  5: 50}, order_of_key(3) -> return index 2