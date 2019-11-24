#include "imodule.h"

#include "MD5ModelLoader.h"
#include "MD5AnimationCache.h"

#include "modulesystem/StaticModule.h"

namespace md5
{

class MD5Module :
	public RegisterableModule
{
public:
	// RegisterableModule implementation
	const std::string& getName() const
	{
		static std::string _name("MD5Module");
		return _name;
	}

	const StringSet& getDependencies() const
	{
		static StringSet _dependencies;

		if (_dependencies.empty())
		{
			_dependencies.insert(MODULE_MODELFORMATMANAGER);
		}

		return _dependencies;
	}

	void initialiseModule(const ApplicationContext& ctx)
	{
		GlobalModelFormatManager().registerImporter(std::make_shared<md5::MD5ModelLoader>());
	}
};

// Static module instances
module::StaticModule<md5::MD5Module> md5Module;
module::StaticModule<md5::MD5AnimationCache> md5AnimationCache;

}
