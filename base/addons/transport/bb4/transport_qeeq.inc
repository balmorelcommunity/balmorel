* Transport add-on. Added by Juan Gea Bermudez

*adding electricity demand from transport
$ifi %TRANSPORT_SYNTHFUEL_COMMODITY%==ELECTRICITY  +VTRANSDEMAND_T(IY411,IR,IS3,T)$SUM(C,TRANSDEMAND_Y(IY411,C))