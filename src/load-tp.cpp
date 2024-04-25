#include <Geode/Geode.hpp>
using namespace geode::prelude;

$on_mod(Loaded) {
	auto asd = Mod::get()->getTempDir();
	auto zip = asd / "resources" / "user95401.guschin_ps" / "pack.zip";
	//unzip
	auto unzip = geode::utils::file::Unzip::intoDir(zip, asd / "pack");
	//tp
	CCTexturePack tp;
	tp.m_id = Mod::get()->getID();
	tp.m_paths = { (asd / "pack").string() };
	CCFileUtils::sharedFileUtils()->addTexturePack(tp);
}