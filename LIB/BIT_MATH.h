

#ifndef  BIT_MATH_H_
#define  BIT_MATH_H

#define  SET_BIT(REG,BIT)              (REG |= (1 << BIT))
#define  CLR_BIT(REG,BIT)              (REG &= ~(1 << BIT))
#define  GET_BIT(REG,BIT)              ((REG >> BIT) & 1)
#define  TOG_BIT(REG,BIT)              (REG ^= (1 << BIT))
#define  WRITE_REG(REG,VALUE)          (REG = VALUE)
#define MODIFY_REG(REG,SET_MASK,CLEAR_MASK)  ( WRITE_REG(REG,(REG &(~(CLEAR_MASK))) |SET_MASK))




#endif
