////////////////////////////////////
//文件说明:ftp_server.c
//作者:高小调
//创建时间:2017年07月14日 星期五 14时45分13秒
//开发环境:Kali Linux/g++ v6.3.0
////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
//创建监听套接字,并返回
int create_socket(const char* port){
	//创建套接字
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0){
		perror("socket");
		exit(1);
	}
	//绑定端口
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(port));
	local.sin_addr.s_addr = 0;
	if(bind(sock,(struct sockaddr*)&local,sizeof(local)) <0){
		perror("bind");
		exit(2);
	}
	if(listen(sock,10) < 0){
		perror("listen");
		exit(3);
	}
	return 0;
}
int main(int argc,const char*argv[]){
	//参数合法性检查
	if(argc!=2){
		printf("Usage:%s [port]\n",argv[0]);
		return 1;
	}
	//创建监听套接字
	int listen_sock = create_socket(argv[1]);

	return 0;
}
