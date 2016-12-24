#pragma once
struct iterator {
	iterator() {}
	iterator(const iterator & m) : _pos(m._pos), _farr(m._farr) {}
	iterator(for1array<value_type> * forarray, size_type pos) : _pos(pos), _farr(forarray) {}

	reference operator*() const
	{	// return designated object
		return (*_farr)[_pos];
	}

	pointer operator->() const
	{	// return pointer to class object
		return &(*_farr)[_pos];
	}

	iterator& operator++()
	{	// preincrement
		++_pos;
		return (*this);
	}

	iterator operator++(int)
	{	// postincrement
		iterator tmp = *this;
		++_pos;
		return (tmp);
	}

	iterator& operator--()
	{	// predecrement
		--_pos;
		return (*this);
	}

	iterator operator--(int)
	{	// postdecrement
		iterator tmp = *this;
		--_pos;
		return (tmp);
	}

	bool operator==(const iterator& _right) const
	{	// test for iterator equality
		return _right._pos == _pos && _right._farr == _farr;
	}

	bool operator!=(const iterator& _right) const
	{	// test for iterator inequality
		return _right._pos != _pos || _right._farr != _farr;
	}

	bool operator<(const iterator& _right) const
	{	// test if this < _Right
		return _pos < _right._pos;
	}

	bool operator>(const iterator& _right) const
	{	// test if this > _Right
		return _pos > _right._pos;
	}

	bool operator<=(const iterator& _right) const
	{	// test if this <= _Right
		return _pos <= _right._pos;
	}

	bool operator>=(const iterator& _right) const
	{	// test if this >= _Right
		return _pos >= _right._pos;
	}
protected:
	size_type _pos;
	for1array<value_type> * _farr;
};