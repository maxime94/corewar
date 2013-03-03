/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:54:01 2013 luc sinet
*/

#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem ld the
** champs.
** \return the total size of the instruction !
*/
int	op_lld(t_process *proc, t_vm *vm)
{
  int	reg;
  int	vtl;

  vtl = 0;
  reg = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 1) + 1] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      if (GET_TYPE_PARAMX(PARAMBYTE, 0) == 1)
        vtl = op_get_reg(proc, vm, 0);
      else if(GET_TYPE_PARAMX(PARAMBYTE, 0) == 2)
        vtl = op_get_dir(proc, vm, 0);
      else
        vtl = op_get_ind(proc, vm, 0, 0);
      proc->reg[reg] = vtl;
      proc->carry = is_byte_zero((char*) & (proc->reg[reg]), sizeof(int));
      printf("[%10s] lld (i@pc+%d=%d -> reg%d) carry = %d\n", proc->associated_champ->header.prog_name, vtl, proc->reg[reg], reg, proc->carry);
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1) + 2);
}
