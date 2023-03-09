

// n= no of nodes
// k = no of connections
// u ,v values inside nodes
// connected_componenets_cnt  == no of parent nodes (each group has 1 parent)


int main() {
	int n , k ;
	cin >> n >> k ;

	for ( int i = 0 ; i < n ; i++) {
		make(i);
	}

	while (k--) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	int connected_componenets_cnt ;

	for (int i ; i <= n ; i++) {
		if (find[i] == i) {
			connected_componenets_cnt++;
		}
	}
}










// !!!!!!!!!CONCEPT!!!!!!!!!!!

//parent array
int parent[n];
// each bucket of this array denote // index = number
// value inside = parent of that index
int size[n]; // array that stores SIZE OF THE GROUP of that index
void make(int a) { // makes a new independent node
	parent[a] = a;
	size[a] = 1; // when a new node is made , its size is 1
}
int find(int a) { // FINDS PARENT OF input
	if (parent[a] == a) return a;
	// this condition is satisfied only i arrive at parent node

	//	WITHOUT PATH COMPRESSION
	// if above not satisfied
	//return find(parent[a]);// recursively find parent of a

	// APPLYING PATH COMPRESSION
	return parent[a] = find(parent[a]);
	// IN THE PARENT ARRAY ,
	//EARLIER THE IMMEDIATE PARENT
	// NOW IS REPLACED BY THE FINAL PARENT OF THAT GROUP
	// !!!!!!!!HENCE PATH COMPRESSION !!!!!!!!!
}
void Union(int a, int b) {
	// first we find root of each graph
	a = find(a);
	b = find(b);
	// if parent of a and b are same ,  we do nothing, as they are from same GROUP
	if (a != b ) {

		// !!!!!!!!!!UNION BY SIZE!!!!!!!!!!
		// FOR BEST OPTIMIZATION , WE ALWAYS ADD SMALL GROUP TO LARGER GROUP
		// so a = larger always
		// b = smaller alwys
		if (size[a] < size[b]) {
			swap(a, b);
		}
		// join parent of one group to parent of other
		parent[b] = a; // JOINTING PARENTS(ROOTS ) OF TWO GROUPS
		//now two groups have been merged
		size[a] += size[b];
	}

}



