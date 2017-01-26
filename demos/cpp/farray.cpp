void test_hiddendo_constructor(){
	farray<int> e = make_farray({ 1,1 }, { 2,2 }, [](const fsize_t * current) {return ([](fsize_t i, fsize_t j) {return i + j;  })(current[0], current[1]); });
	forprintfree(e); // 2 3 3 4
	forprint("%d %d\n", e); // 2 3\n 3 4
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

void test_transpose(){
	farray<int> a({ 1,1,1 }, { 2,2,2 });
	farray<int> b({ 1,1,1 }, { 2,2,2 });
	a = forreshape({ 1, 2, 3, 4, 5, 6, 7, 8 }, { 2, 2, 2 });
	b = forreshape({ 1, 2, 3, 4, 5, 6, 7, 8 }, { 2, 2, 2 });
	b.transpose();
	//forprintfree(a(2, 2, 1) , "  ", b(1 ,2 ,2));
	farray<int> c({ 1,1 }, { 2,3 });
	farray<int> d({ 1,1 }, { 2,3 });
	c = forreshape({ 1, 2, 3, 4, 5, 6 }, { 2, 3 });
	d = forreshape({ 1, 2, 3, 4, 5, 6 }, { 2, 3 });
	d.transpose();
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			forprintfree(i, j);
			forprintfree(c(i, j)); // c(i, j) must equal with d(j, i)
			forprintfree(d(j, i));
			forprintfree("\n");
		}
	}
	system("pause");
	return 0;
}

void test_maxloc(){
// result in http://www.lahey.com/docs/lfprohelp/F95ARMAXLOCFn.htm
	farray<int > a{ { 1, 1 },{ 2, 3 }, { -14,3,0,-2,19,1 } };
	forprintfree(formaxloc(a, 1), "\n"); // 2 1 1
	forprintfree(formaxloc(a, 2), "\n"); // 3 1
}