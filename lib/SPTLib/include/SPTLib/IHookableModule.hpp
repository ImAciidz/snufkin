#pragma once

#include <cstddef>
#include <string>
using std::size_t;

#include "MemUtils.hpp"
#include "patterns.hpp"

class IHookableModule {
public:
	virtual ~IHookableModule() {}
	virtual bool CanHook(const std::wstring& moduleFullName) = 0;
	virtual void* GetHandle();
	virtual std::wstring GetName();
	virtual void* GetBase();
	virtual size_t GetLength();

	virtual void Hook(const std::wstring& moduleName,
	                  void* moduleHandle,
	                  void* moduleBase,
	                  size_t moduleLength,
	                  bool needToIntercept) = 0;
	virtual void Unhook() = 0;
	virtual void Clear();

	virtual void TryHookAll(bool needToIntercept) = 0;

protected:
	void* m_Handle;
	void* m_Base;
	size_t m_Length;
	std::wstring m_Name;
	bool m_Intercepted;
};
