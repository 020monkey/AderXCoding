#ifndef COMDEF_H_INCLUDE
#define COMDEF_H_INCLUDE


/// ��ǰ�ַ�������
#define IsDigit(c)         (c >= '0' && c <= '9')

/// ��ǰ�ַ���8��������
#define IsOctDigit(c)      (c >= '0' && c <= '7')

/// ��ǰ�ַ���16��������
#define IsHexDigit(c)      (IsDigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))

/// ��ǰ�ַ�����ĸ����_
#define IsLetter(c)        ((c >= 'a' && c <= 'z') || (c == '_') || (c >= 'A' && c <= 'Z'))

/// ��ǰ�Ը��Ƿ�����C�ı�����������
#define IsLetterOrDigit(c) (IsLetter(c) || IsDigit(c))
#define IsIdentifier    IsLetterOrDigit

/// ��ǰ�ַ��ǿհ��ַ�
#define IsSpace(c)  ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')



/// ȡ����ǰ��Ϣ�ĸ�4λ
#define HIGH_4BIT(v)       ((v) >> (8 * sizeof(int) - 4) & 0x0f)
/// ȡ����ǰ��Ϣ�ĸ�3λ
#define HIGH_3BIT(v)       ((v) >> (8 * sizeof(int) - 3) & 0x07)
/// ȡ����ǰ��Ϣ�ĸ�1λ
#define HIGH_1BIT(v)       ((v) >> (8 * sizeof(int) - 1) & 0x01)
#define ALIGN(size, align) ((size + align - 1) & (~(align - 1)))

#define BitGet(number, pos) ((number) >> (pos) & 1)     /// �ú�õ�ĳ����ĳλ
#define BitSet(number, pos) ((number) |= 1 << (pos))    /// ��ĳλ��1
#define BitClr(number, pos) ((number) &= ~(1 << (pos))) /// ��ĳλ��0
#define BitCpl(number, pos) ((number) ^= 1 << (pos))    /// ��number��POSλȡ��


///03: �õ�ָ����ַ�ϵ�һ���ֽڻ���
#define  MEM_B(x) (*((byte *)(x)))
#define  MEM_W(x) (*((word *)(x)))

///04: �����ֵ����Сֵ
#define  MAX(x,y) (((x)>(y)) ? (x) : (y))
#define  MIN(x,y) (((x) < (y)) ? (x) : (y))

///05: �õ�һ��field�ڽṹ��(struct)�е�ƫ����
#define FPOS(type,field) ((dword)&((type *)0)->field)

///06: �õ�һ���ṹ����field��ռ�õ��ֽ���
#define FSIZ(type,field) sizeof(((type *)0)->field)

///07: ����LSB��ʽ�������ֽ�ת��Ϊһ��Word
#define FLIPW(ray) ((((word)(ray)[0]) * 256) + (ray)[1])

///08: ����LSB��ʽ��һ��Wordת��Ϊ�����ֽ�
#define FLOPW(ray,val) (ray)[0] = ((val)/256); (ray)[1] = ((val) & 0xFF)

///09: �õ�һ�������ĵ�ַ��word��ȣ�
#define B_PTR(var)  ((byte *) (void *) &(var))
#define W_PTR(var)  ((word *) (void *) &(var))

///10: �õ�һ���ֵĸ�λ�͵�λ�ֽ�
#define WORD_LO(xxx)  ((byte) ((word)(xxx) & 255))
#define WORD_HI(xxx)  ((byte) ((word)(xxx) >> 8))

///11: ����һ����X�����ӽ���8�ı���
#define RND8(x) ((((x) + 7)/8) * 8)

///12: ��һ����ĸת��Ϊ��д
#define UPCASE(c) (((c)>='a' && (c) <= 'z') ? ((c) - 0x20) : (c))
#define ToUpper(c)		   (c & ~0x20)

///13: �ж��ַ��ǲ���10��ֵ������
#define  DECCHK(c) ((c)>='0' && (c)<='9')

///14: �ж��ַ��ǲ���16��ֵ������
#define HEXCHK(c) (((c) >= '0' && (c)<='9') ((c)>='A' && (c)<= 'F') \
((c)>='a' && (c)<='f'))

///15: ��ֹ�����һ������
#define INC_SAT(val) (val=((val)+1>(val)) ? (val)+1 : (val))

///16: ��������Ԫ�صĸ���
#define ARR_SIZE(a)  (sizeof((a))/sizeof((a[0])))

///17: ����һ���޷�����nβ��ֵMOD_BY_POWER_OF_TWO(X,n)=X%(2^n)
#define MOD_BY_POWER_OF_TWO( val, mod_by ) ((dword)(val) & (dword)((mod_by)-1))

///18: ����IO�ռ�ӳ���ڴ洢�ռ�Ľṹ,�����������
#define inp(port) (*((volatile byte *)(port)))
#define inpw(port) (*((volatile word *)(port)))
#define inpdw(port) (*((volatile dword *)(port)))
#define outp(port,val) (*((volatile byte *)(port))=((byte)(val)))
#define outpw(port, val) (*((volatile word *)(port))=((word)(val)))
#define outpdw(port, val) (*((volatile dword *)(port))=((dword)(val)))




/**
 * Macros to help with debugging. Set SCULL_DEBUG to 1 enable
 * debugging (which you can do from the Makefile); these macros work
 * in both kernelspace and userspace.
 */

/* undef it, just in case someone else defined it. */

#ifdef dbgprint
#undef dbgprint
#endif // dbgprint

#ifdef dprint
#undef dprint
#endif // dprint

#ifdef dout
#undef dount
#endif // dout


/**when you define DEBUG macro
    dbgprint to use printk with line and funcitonname in kernel
    dprint to use print without line and funcitonname in kernel


    dbgprint to use printf with line and funcitonname in userspace
    dprint to use printf without line and funcitonname in userspace
    it's the same to dbgcout and dcout in userspace

*/
#ifdef DEBUG

    #ifdef __KERNEL__
        #ifdef __FILE__ && __LINE__
            //printk with line and function name
            #define dbgprint(format,args...); \
            printk(KERN_INFO "[%s, %d] : "format, __FILE__, __LINE__, ##args);
        #endif

        //printk without line and function name
        #define dprint(format,args...); printk(KERN_INFO format, ##args);


    #else   //  userspace

        #ifdef __FILE__ && __LINE__
            //printf with line and function name
            #define dbgprint(format,args...); \
            printf("[%s,%d] : "format, __FILE__, __LINE__, ##args);
            #define dbgcout cout <<"[" <<__FILE__ <<", " <<__LINE__ <<"] : "

        #endif // __FILE__ && __LINE__

            /* Debugging is on and we are in userspace. */
            #define dprint(fmt, args...) printf(fmt, ## args)
            #define dcout cout


    #endif // __KERNEL__

#else           /* Not debugging: do nothing. */
    #define dbgprint(format,args...)

    #define dprint(fmt, args...)
    #define dcout 0 && cout
#endif

/* PDEBUGG is a placeholder that makes it easy to "comment out" the debugging
   statements without deleting them. */
#undef undprint
#define undprint(fmt, args...)
#define undcout 0 && count





#endif // COMDEF_H_INCLUDE


