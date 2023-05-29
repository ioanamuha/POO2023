#ifndef MAP_H
#define MAP_H

#include <iostream>

template <typename K, typename V>
class Map {
	struct Elem {
		K k;
		V v;
		int index;
	} *vect;

	int nrElemente,i,j,marime;
	int grow = 10;
	void Resize()
	{
		if (marime != 0)
		{
			Elem* aux = new Elem[marime+grow];
			memcpy(aux, vect, sizeof(Elem) * marime);
			vect = aux;
			marime = marime+grow;
			return;
		}
		vect = new Elem[10];
		marime = 10;
		nrElemente = 0;
	}
public:
	Map()
	{
		vect = new Elem[10];
		marime = 10;
		nrElemente = 0;
	}

	Elem* begin() const { return &vect[0]; }
	Elem* end() const { return &vect[this->nrElemente]; }

	V& operator [] (K key)
	{
		for (i = 0; i < nrElemente; i++)
		{
			if (key == vect[i].k)
				return vect[i].v;
		}
		vect[this->nrElemente].index = this->nrElemente;
		vect[this->nrElemente].k = key;
		this->nrElemente++;
		if (this->nrElemente == marime)
			Resize();
		return vect[this->nrElemente - 1].v;
	}

	void Set(K key, V value)
	{
		for (i = 0; i < nrElemente; i++)
		{
			if (vect[i].k == key)
			{
				vect[i].v = value;
				marime++;
				return;
			}
		}
		return;
	}

	bool Get(const K& key, V& value)
	{
		for (i = 0; i < nrElemente; i++)
		{
			if (vect[i].k == key)
			{
				value = vect[i].v;
				return true;
			}
		}
		return false;
	}

	int Count() const
	{
		return nrElemente;
	}

	void Clear()
	{
		marime = 0;
		nrElemente = 0;
		delete[] vect;
	}

	bool Delete(const K& key)
	{
		for (i = 0; i < nrElemente; i++)
		{
			if (vect[i].k == key)
			{
				for (j = i; j < nrElemente - 1; j++)
					vect[j] = vect[j + 1];
				nrElemente--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)	
	{
		if (map.nrElemente < nrElemente) return false;

		bool ok;
		for (i = 0; i < nrElemente; i++)
		{
			ok = 0;
			for (j = 0; j < map.nrElemente; j++)
				if (vect[j].k == map.vect[i].k)
				{
					ok = 1;
					break;
				}
			if (ok == 0)
				return false;
		}
		return true;
	}
};

#endif