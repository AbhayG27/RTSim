#include <cache.h>
cache::cache() {
}
int cache::exists(mem_addr_t key) {
	/*cache_tag_t tag = key >> (MEM_SIZE / CACHE_SIZE);
	map<cache_tag_t,pair<cache_index_t, mem_block_t>>::iterator it = cacheFile.find(tag);
	if (it == cacheFile.end)
		return -1;
	else if (it->second.first != key&(MEM_SIZE / CACHE_SIZE - 1)) {
		return -1;
	}
	else*/
		return 1;
}
int cache::get(mem_addr_t key, mem_block_t &item) {
	/*cache_tag_t tag = key >> (MEM_SIZE / CACHE_SIZE);
	item=cacheFile.at(tag).second;*/
	return CACHE_READ_LATENCY;
}
int cache::put(mem_addr_t key, mem_block_t item) {
	/*pair<cache_tag_t, pair<cache_index_t, mem_block_t>> temp;
	temp.first = key>> (MEM_SIZE / CACHE_SIZE);
	temp.second.first = key&(MEM_SIZE / CACHE_SIZE - 1);
	temp.second.second = item;
	cacheFile.insert(temp);*/
	return CACHE_WRITE_LATENCY;
}
cache::~cache() {

}