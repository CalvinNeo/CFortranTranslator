void test_hiddendo_constructor(){
	farray<int, 2> e({ 1,1 }, { 2,2 }, [](const fsize_t * current) {return ([](fsize_t i, fsize_t j) {return i + j;  })(current[0], current[1]); });
	forprintfree(e);
	forprint("%d %d\n", e);
	forreadfree(stdin, e);
	forprintfree(e);
}

void test_merge(){
	farray<int, 2> a({ 1, 1 }, { 2, 3 }, { 1, 2, 3, 4, 5, 6 });
	farray<int, 2> a1({ 1, 1 }, { 2, 3 }, { 8, 9, 0, 1, 2, 3 });
	farray<bool, 2> logi({ 1, 1 }, { 2, 3 }, {false, true, true, true, true, false });
	forprintfree(formerge(a, a1, logi));
}