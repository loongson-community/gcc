;; FOR G3A 128-bit mem access instructions
;; gssq and gslq define_insn pattern
(define_insn "movsqdi_internal"
  [(parallel [(set (match_operand:DI 0 "stack_operand" "")
                   (match_operand:DI 1 "register_operand" ""))
              (set (match_operand:DI 2 "stack_operand" "")
                   (match_operand:DI 3 "register_operand" ""))])]
  "mips_gs464_128_store_p(operands)"
  {
    return "gssq\t%1,%3,%2";
  }
  [(set_attr "length" "8")
   (set_attr "can_delay" "no")])

(define_insn "movsqdf_internal"
  [(parallel [(set (match_operand:DF 0 "stack_operand" "")
                   (match_operand:DF 1 "register_operand" ""))
              (set (match_operand:DF 2 "stack_operand" "")
                   (match_operand:DF 3 "register_operand" ""))])]
  "mips_gs464_128_store_p(operands)"
  {
    return "gssqc1\t%1,%3,%2";
  }
  [(set_attr "length" "8")
   (set_attr "can_delay" "no")])

(define_insn "movlqdi_internal"
  [(parallel [(set (match_operand:DI 0 "register_operand" "")
                   (match_operand:DI 1 "stack_operand" ""))
              (set (match_operand:DI 2 "register_operand" "")
                   (match_operand:DI 3 "stack_operand" ""))])]
  "mips_gs464_128_load_p(operands)"
  {
    return "gslq\t%0,%2,%3";
  }
  [(set_attr "length" "8")
   (set_attr "can_delay" "no")])

(define_insn "movlqdf_internal"
  [(parallel [(set (match_operand:DF 0 "register_operand" "")
                   (match_operand:DF 1 "stack_operand" ""))
              (set (match_operand:DF 2 "register_operand" "")
                   (match_operand:DF 3 "stack_operand" ""))])]
  "mips_gs464_128_load_p(operands)"
  {
    return "gslqc1\t%0,%2,%3";
  }
  [(set_attr "length" "8")
   (set_attr "can_delay" "no")])

