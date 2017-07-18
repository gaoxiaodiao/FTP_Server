#!/usr/bin/python
#coding=utf-8
"""
*文件说明:ftp_server.py
*作者:高小调
*创建时间:2017年07月18日 星期二 14时00分03秒
*开发环境:Kali Linux/Python v2.7.13
"""
from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer

# 实例化虚拟用户
authorizer = DummyAuthorizer()
#添加用户权限与路径
authorizer.add_user("gxd","123456","/home/",perm="elradfmw")
#添加匿名用户
authorizer.add_anonymous("/usr/gxd");
#初始化ftp句柄
handler = FTPHandler
handler.authorizer = authorizer

#修正服务器返回ip与端口
handler.masquerade_address = "115.29.44.103"
#被动端口范围设置
handler.passive_ports = range(2048,4096)

#监听ip、端口
server = FTPServer(("0.0.0.0",21),handler)
#启动服务
server.serve_forever()

