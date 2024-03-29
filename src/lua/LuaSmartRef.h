#pragma once
#include "LuaCompat.h"

class LuaSmartRef
{
	int ref = LUA_REFNIL;

public:
	~LuaSmartRef();
	void Assign(lua_State *l, int index); // Copies the value before getting reference, stack unchanged.
	void Clear();
	int Push(lua_State *l); // Always pushes exactly one value, possibly nil.

	inline operator int() const
	{
		return ref;
	}

	inline operator bool() const
	{
		return ref != LUA_REFNIL;
	}
};
