#pragma once

#include <string>
#include <vector>

#include "IHookableModule.hpp"

namespace Hooks {
	void Init(bool needToIntercept);
	void Free();
	void Clear();

	void InitInterception(bool needToIntercept);
	void ClearInterception(bool needToIntercept);

	void HookModule(std::wstring moduleName);
	void UnhookModule(std::wstring moduleName);


	bool DebugEnabled();

	extern std::vector<IHookableModule*> modules;
}; // namespace Hooks
