#include <Geode/Geode.hpp>
using namespace geode::prelude;

void sned(CCHttpClient* self, CCHttpRequest* request) {
	//the_url
	std::string the_url = request->getUrl();
	//repl vars
	std::string target = "www.boomlings.com/database";
	std::string replaceto = "guschin.zahann.ru/database";
	//do replace the url
	if (the_url.find(target) != std::string::npos) {
		//yea
		the_url.replace(the_url.find(target), target.length(), replaceto);
		//log it
		log::debug("{} => {}", request->getUrl(), the_url.data());
		//set url
		request->setUrl(the_url.c_str());
	};
	// Call the original
	self->send(request);
}

$execute{
	Mod::get()->hook(
		reinterpret_cast<void*>(
			// All of this is to get the address of ccDrawCircle
			geode::addresser::getNonVirtual(
				// This is used because this function is overloaded,
				// otherwise just a regular function pointer would suffice (&foobar)
				geode::modifier::Resolve<CCHttpRequest*>::func(&cocos2d::extension::CCHttpClient::send)
			)
		),
		&sned, // Our detour
		"cocos2d::extension::CCHttpClient::send", // Display name, shows up on the console
		tulip::hook::TulipConvention::Thiscall // Static free-standing cocos2d functions are cdecl
	);
}
