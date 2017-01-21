void test_hiddendo_constructor(){
	farray<int> e({ 1,1 }, { 2,2 }, [](const fsize_t * current) {return ([](fsize_t i, fsize_t j) {return i + j;  })(current[0], current[1]); });
	forprintfree(e);
	forprint("%d %d\n", e);
	forreadfree(stdin, e);
	forprintfree(e);
}

void test_combined_constructor(){
	farray<int > d({5}, {3}, {farray<T>({5}, {3}, forslice(a, {{5, 2}})) , farray<T>({5}, {3}, b(5)(6)) , farray<T>({5}, {3}, [](const fsize_t(&current)[1]){return [](fsize_t i){return to_int(i) + 1;}(current[0]);})});
	forprintfree(d);
}

void test_merge(){
	farray<int> a({ 1, 1 }, { 2, 3 }, { 1, 2, 3, 4, 5, 6 });
	farray<int> a1({ 1, 1 }, { 2, 3 }, { 8, 9, 0, 1, 2, 3 });
	farray<bool> logi({ 1, 1 }, { 2, 3 }, {false, true, true, true, true, false });
	forprintfree(formerge(a, a1, logi));
	// 8 2 3 4 5 3
}