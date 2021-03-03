#include<iostream>
#include<cassert>
#include<leveldb/db.h>

// g++ -o snapshotTest snapshotTest.cpp -I include ./lib/libleveldb.a -pthread
int main(void)
{
	leveldb::DB *db;
	leveldb::Options options;
	options.create_if_missing=true;
	leveldb::Status status=leveldb::DB::Open(options,"mydb2",&db);
	assert(status.ok());
	std::string key1="fruit";
	std::string value1="apple";
	status=db->Put(leveldb::WriteOptions(),key1,value1);
    // 一开始先往数据库插入一条键值对，接着再插入一条键值一样的记录，最后读出这个键值对应的value时，显示为最新的数据，也就是orange。
	assert(status.ok());
	leveldb::ReadOptions readoptions;
	readoptions.snapshot=db->GetSnapshot();		// 快照， 时间点在两个put之间
	 std::string value2="orange";
	 status=db->Put(leveldb::WriteOptions(),key1,value2);
	 assert(status.ok());
	 std::string value;
	 status=db->Get(readoptions,key1,&value);
    	assert(status.ok());
	 std::cout<<value<<std::endl;
	 //db->ReleaseSnapshot(readoptions.snapshot);

	 // 当我把两个注释去掉，并且把db->Get方法里的leveldb::ReadOptions()改成第一个注释中的readoptions时，这时输出为快照之前的数据，为apple。
	 delete db;
	 return 0;
}