void	PmergeMe::recur(std::vector< std::pair<int,int> > input) {
	std::vector< std::pair<int,int> > to_next;
	for (size_t i = 0; i < input.size() - 1; i += 2) {
		std::pair<int, int> pair;
		if (input[i].second >= input[i + 1].second) {
			pair.second = input[i].second;
			pair.first = input[i + 1].second;
		} else {
			pair.second = input[i + 1].second;
			pair.first = input[i].second;
		}
		to_next.push_back(pair);
	}
	if (!is_sort(input))
		recur(to_next);

	if (_final.size() == 0) {
		_final.insert(_final.begin(), input[0].second);
		input[0].second += 10;
		_final.insert(_final.begin(), input[0].first);
		input[0].first += 10;
	}
	std::cout << "---------INPUT----------" << std::endl;
	print_pair_vec(input);
	std::cout << "---------TO_NEXT----------" << std::endl;
	print_pair_vec(to_next);
	std::cout << "---------FINAL----------" << std::endl;
	print_all(_final);
	size_t distance = jacobsthal(++_jacob_number);
	std::cout << "distance " << distance << std::endl;
	if (distance > _final.size())
		distance = _final.size() - 1 ;
	size_t last_jacob_number = jacobsthal(_jacob_number - 1);
	std::cout << "size = " << input.size() << std::endl;
	std::cout << "Jacob Number =" << _jacob_number << std::endl;
	std::cout << "Last Jacob Number =" << last_jacob_number << std::endl;
	std::cout << "\n\n\n" << std::endl;


	while (distance >= last_jacob_number && distance <= static_cast<size_t>(_jacob_number)) {
		std::cout << "Dist = " << distance << std::endl;
		int i = find_small(input, _final[distance], _final, distance);
		if (i == -1)
			break;
		std::cout << "i  = " << i << "next first value " << input[i].first << std::endl;
		for(std::vector<int>::iterator it=_final.begin() + jacobsthal(_jacob_number); it!=_final.begin(); --it) {
			std::cout << "iterator value = " << *it << std::endl;
			if (*it > input[i].first && ( it == _final.begin() || *(it - 1) < input[i].first)) {
				_final.insert(it, input[i].first);
				input[i].first += 10;
				input[i].second += 10;
				break;
			}
			if ((it - 1) == _final.begin()) {
				_final.insert((it - 1), input[i].first);
				input[i].first += 10;
				input[i].second += 10;
				print_all(_final);
				break;
			}
		}
		distance--;
	}
}
//				std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
//	print_pair_vec(to_next);
//	print_pair_vec(input);
//	for(size_t i= to_next.size(); i > 0 ; i--) {
//		if (to_next[i].second != 10) {
//			for(std::vector<int>::iterator it=_final.begin() ; it!=_final.end(); it++) {
//				if (*it < to_next[i].second) {
//					_final.insert(it, to_next[i].second);
//					to_next[i].second = 10;
//					while (--it != _final.begin()) {
//						if (*it < to_next[i].first) {
//							_final.insert(it, to_next[i].first);
//							to_next[i].first = 10;
//						}
//					}
//					if (to_next[i].first != 10)
//						_final.insert(it, to_next[i].first);
//				}
//			}
//		}
//	}
//	std::cout << "Final end of recur" << std::endl;

std::vector<std::pair< int , int > >::iterator PmergeMe::find_iter(std::vector<std::pair< int , int > > V, int i) {
	int find = 0;
	for (std::vector<std::pair< int , int > >::iterator it = V.begin(); it != V.end(); it++) {
		if (find == i)
			return it;
		find++;
	}
	std::vector<std::pair< int , int > >::iterator it = V.end();
	return it;
}
//			std::cout << "BBB" << std::endl;
//		std::cout << "AAA" << std::endl;

//rest of elements
//	else {
//		for (std::vector<std::pair<int ,int > >::iterator it = to_next.begin(); it < to_next.end(); it++) {
//			if (_final[j / 2] < it)
//			_final.push_back(to_next[j].first);
//		}
//	}

bool PmergeMe::is_sort(std::vector<std::pair<int, int> > input) {
	for (size_t i = 0; i < input.size() - 1; i++) {
		if (input[i].second > input[i + 1].second)
			return false;
	}
	return true;
}

int PmergeMe::find_small(std::vector<std::pair<int, int> > haystack, int to_find, std::vector<int> _final, int position) {
	for (int i = position; i >= 0 && i <= position; --i) {
		for (size_t it = 0; it < haystack.size(); it++) {
			if (haystack[it].second == _final[i])
				return static_cast<int>(it);
		}
	}

	return -1;
}



void PmergeMe::print_all(std::vector<int> &J) {
	std::cout << "RESULT of " << J.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=J.begin(); it!=J.end(); ++it) {
		std::cout << *it << ", " ;
	}
	std::cout << std::endl;
}