// ar is input array
// st is segment tree array of size ~= 4n, where n= size of ar 
// si - segment index, ss - segment start index, se - segment end index, qi - query index

void segment_tree_point_update(int si, int ss, int se, int qi){
    if(ss==se){
    	st[si]=ar[ss];
    	return;
    }

    int mid = ss + (se-ss)/2;
    if(qi<=mid)
    	segment_tree_point_update(2*si, ss, mid, qi);
    else
    	segment_tree_point_update(2*si+1, mid+1, se, qi);

    st[si] = min(st[2*si], st[2*si+1]);
}