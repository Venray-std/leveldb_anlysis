leveldb对用户提供两个可以写入数据的接口：
 Status Write(const WriteOptions& options, WriteBatch* updates);
 Status Put(const WriteOptions&, const Slice& key, const Slice& value);

 两个参数的形参不一样，第一个是writebatch，第二个是key-value。第二个比较好理解，第一个是什么意思呢？其实顾命思议，writebatch就是批量写入。