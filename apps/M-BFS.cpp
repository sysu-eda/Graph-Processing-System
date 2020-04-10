// This code is part of the project "Krill"
// Copyright (c) 2019 Hongzheng Chen

#include "krill.h"
#include "Homo1.pb.h"
#include "BFS.h"
using namespace std;

template <class vertex>
void setKernels(graph<vertex>&G, Kernels& K, commandLine P)
{
	Homo1::Property prop(G.n);
	for (int i = 1; i < 9; ++i){
		int start = 91 * i;
		if (start >= G.n)
			start = i;
		BFS* bfs = new BFS(G.n, prop.add_parents(), start); // remember to dynamically allocate memory
		K.appendJob(bfs);
	}
}