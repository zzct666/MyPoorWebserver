#pragma once
//服务器要处理的业务逻辑

// 初始化监听的文件描述符
int initListenFd(unsigned short port);
//启动epoll模型
int epollRun(unsigned short port);
//和客户端建立连接
int acceptConn(int lfd, int epfd);
//接收客户端的http请求消息
int recvHttpRequest(int cfd);
//解析请求行
int parseRequestLine(const char* reqLine);
//发送头信息  （状态行 + 消息报头 + 空行）
int sendHeadMsg(int cfd);
//读文件内容,并发送
int sendFile(const char* filename);
