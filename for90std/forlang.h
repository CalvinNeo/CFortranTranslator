#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

namespace for90std {
	template <class T>
	struct foroptional
	{
		operator T() const {
			return value;
		}

		T & operator= (const T & newv) {
			// ��ֵ�����
			invalid = true;
			value = newv;
			return value;
		}
		foroptional(const T & newv) {
			// ����ֵ��ʼ����˵������Ĭ�ϳ�ʼ��
			invalid = true;
			value = newv;
		}
		foroptional(T & newv) {
			// ����ֵ��ʼ����˵������Ĭ�ϳ�ʼ��
			invalid = true;
			value = newv;
		}
		foroptional(const foroptional<T> & newv) {
			// ���ƹ��캯��
			invalid = true;
			value = newv.const_get();
		}
		foroptional(foroptional<T> & newv) {
			// ���ƹ��캯��
			invalid = true;
			value = newv.get();
		}
		foroptional() {
			// Ĭ�ϳ�ʼ��
			invalid = false;
		}
		bool inited() const {
			return invalid;
		}
		T get() {
			return value;
		}
		const T & const_get() const {
			return value;
		}
	private:
		T value;
		bool invalid = false;
	};

	template <class T>
	bool forpresent(foroptional<T> x) {
		return x.inited();
	}

	template<typename T>
	int to_int(T  x) {
		return (int)x;
	}
}