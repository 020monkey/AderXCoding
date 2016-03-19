/*
 * =============================================================================
 *
 *       Filename:  cat.h
 *
 *    Description:  cat class derived from animal base class.
 *
 *        Created:  12/31/2012 12:44:05 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include "animal-base.h"

typedef struct cat_s_ cat_t;

struct cat_s_ {
    animal_t base; /* �̳��� animal ���� */

    /* ���»���������� cat ��ص����Ժͷ���(����ָ��), ��: */
    /* char *owner; // cat ������ */
    /* void (*hunt)(const char *rabbit); // ����Ȯ */
};

extern cat_t * cat_init();
extern void cat_die(cat_t * cat);
���ƴ���