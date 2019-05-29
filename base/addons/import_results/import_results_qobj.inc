* File HYRSBB123addobj.inc for the Balmorel model.
* For use with addon HYRSBB123.
* Included into the objective function QOBJ in Balmorel.gms.

$ifi %HYRSBB123%==none    $goto label_no_hydro_results_import

$ifi not %HYRSBB123%==contprice    $goto label_no_hydro_contprice
                                         +    SUM((IA,S,T)$(IS3(S) AND NOT(IS3(S++1)) AND ORD(T) EQ 1 AND SUM(IGHYRS,IAGK_HASORPOT(Y,IA,IGHYRS))),
                                                 IHOURSINST(S,T)*SUM(ISALIAS$(NOT IS3(ISALIAS)),WATERVAL(Y,IA,ISALIAS))/SUM(ISALIAS$(NOT IS3(ISALIAS)),1)*(VHYRS_SDELTAMWHNEG(Y,IA,S++1)-VHYRS_SDELTAMWHPOS(Y,IA,S++1))
                                        )
$label label_no_hydro_contprice


$label label_no_hydro_results_import

$ifi not %ADDELECSTORCONT%==contprice    $goto label_no_intraseasonal_electricity_storage_content
                                   + SUM((IA,IGESTOS)$IAGK_HASORPOT(Y,IA,IGESTOS),
                                         SUM((S,T)$(IS3(S) AND ORD(T) EQ 1),
                                                 IHOURSINST(S,T)*SUM((ISALIAS,ITALIAS)$(NOT IS3(ISALIAS)),GVESTOVOLTSVAL(Y,IA,IGESTOS,ISALIAS,ITALIAS))/SUM((ISALIAS,ITALIAS)$(NOT IS3(ISALIAS)),WEIGHT_T(ITALIAS))*(VESTOVOLTSDELTAMWHNEG(Y,IA,IGESTOS,S++1,T)-VESTOVOLTSDELTAMWHPOS(Y,IA,IGESTOS,S++1,T))
                                         )
                                   )
$label label_no_intraseasonal_electricity_storage_content

$ifi not %ADDHEATSTORCONT%==contprice    $goto label_no_intraseasonal_heat_storage_content
*                                   + SUM((IA,IGHSTOS)$IAGK_HASORPOT(Y,IA,IGHSTOS),
*                                         SUM((S,T)$(IS3(S) AND ORD(T) EQ 1),
*                                                 IHOURSINST(S,T)*SUM((ISALIAS,ITALIAS)$(NOT IS3(ISALIAS)),GVHSTOVOLTSVAL(Y,IA,IGHSTOS,ISALIAS,ITALIAS))/SUM((ISALIAS,ITALIAS)$(NOT IS3(ISALIAS)),WEIGHT_T(ITALIAS))*(VHSTOVOLTSDELTAMWHNEG(Y,IA,IGHSTOS,S++1,T)-VHSTOVOLTSDELTAMWHPOS(Y,IA,IGHSTOS,S++1,T))
*                                         )
*                                   )

$label label_no_intraseasonal_heat_storage_content

