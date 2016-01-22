#coding=utf-8
#http://blog.csdn.net/gatieme/article/details/45674367

import platform

def TestPlatform( ):
    print ("----------Operation System--------------------------")
    #  ��ȡPython�汾
    print platform.python_version()

    #   ��ȡ����ϵͳ��ִ�г���Ľṹ����(��32bit��, ��WindowsPE��)
    print platform.architecture()

    #   ��������������ƣ���acer-PC��
    print platform.node()

    #��ȡ����ϵͳ���Ƽ��汾�ţ���Windows-7-6.1.7601-SP1��
    print platform.platform()  

    #�������������Ϣ����Intel64 Family 6 Model 42 Stepping 7, GenuineIntel��
    print platform.processor()

    # ��ȡ����ϵͳ��Python�Ĺ�������
    print platform.python_build()

    #  ��ȡϵͳ��python����������Ϣ
    print platform.python_compiler()

    if platform.python_branch()=="":
        print platform.python_implementation()
        print platform.python_revision()

    print platform.release()
    print platform.system()

    #print platform.system_alias()
    #  ��ȡ����ϵͳ�İ汾
    print platform.version()

    #  �����������е���Ϣ����
    print platform.uname()

def UsePlatform( ):
    sysstr = platform.system()
    if(sysstr =="Windows"):
        print ("Call Windows tasks")
    elif(sysstr == "Linux"):
        print ("Call Linux tasks")
    else:
        print ("Other System tasks")




if __name__ == "__main__" :

    TestPlatform( )

    UsePlatform( )