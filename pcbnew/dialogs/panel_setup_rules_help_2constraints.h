// Do not edit this file, it is autogenerated by CMake from the .md file
_HKI( "### Constraints\n"
"\n"
"| Constraint type           | Argument type                                                                                                         | Description                                                                                                                                                                                                                                                                                                                                                                                                                                            |\n"
"|---------------------------|-----------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n"
"| `annular_width`           | min/opt/max                                                                                                           | Checks the width of annular rings on vias.<br>                                                                                                                                                                                                                                                                                                                                                                                                         |\n"
"| `assertion`               | \"&lt;expression>\"                                                                                                     | Checks the given expression.<br>                                                                                                                                                                                                                                                                                                                                                                                                  |\n"
"| `clearance`               | min                                                                                                                   | Specifies the **electrical** clearance between copper objects of different nets.  (See `physical_clearance` if you wish to specify clearance between objects regardless of net.)<br><br>To allow copper objects to overlap (collide), create a `clearance` constraint with the `min` value less than zero (for example, `-1`).<br>                                                                                                                     |\n"
"| `courtyard_clearance`     | min                                                                                                                   | Checks the clearance between footprint courtyards and generates an error if any two courtyards are closer than the `min` distance.  If a footprint does not have a courtyard shape, no errors will be generated from this constraint.<br>                                                                                                                                                                                                              |\n"
"| `creepage`                | min                                                                                                                   | Specifies the **electrical** creepage between copper objects of different nets.<br>                                                                                                                                                                                                                                                                                                                                                                    |\n"
"| `diff_pair_gap`           | min/opt/max                                                                                                           | Checks the gap between coupled tracks in a differential pair.  Coupled tracks are segments that are parallel to each other.  Differential pair gap is not tested on uncoupled portions of a differential pair (for example, the fanout from a component).<br>                                                                                                                                                                                          |\n"
"| `diff_pair_uncoupled`     | max                                                                                                                   | Checks the distance that a differential pair track is routed uncoupled from the other polarity track in the pair (for example, where the pair fans out from a component, or becomes uncoupled to pass around another object such as a via).<br>                                                                                                                                                                                                        |\n"
"| `disallow`                | `track`<br>`via`<br>`micro_via`<br>`buried_via`<br>`pad`<br>`zone`<br>`text`<br>`graphic`<br>`hole`<br>`footprint`<br> | Specify one or more object types to disallow, separated by spaces.  For example, `(constraint disallow track)` or `(constraint disallow track via pad)`.  If an object of this type matches the rule condition, a DRC error will be created.<br><br>This constraint is essentially the same as a keepout rule area, but can be used to create more specific keepout restrictions.<br>                                                                  |\n"
"| `edge_clearance`          | min/opt/max                                                                                                           | Checks the clearance between objects and the board edge.<br><br>This can also be thought of as the \"milling tolerance\" as the board edge will include all graphical items on the `Edge.Cuts` layer as well as any *oval* pad holes.  (See `physical_hole_clearance` for the drilling tolerance.)<br>                                                                                                                                                   |\n"
"| `length`                  | min/max                                                                                                               | Checks the total routed length for the nets that match the rule condition and generates an error for each net that is below the `min` value (if specified) or above the `max` value (if specified) of the constraint.<br>                                                                                                                                                                                                                              |\n"
"| `hole`                    | min/max                                                                                                               | Checks the size (diameter) of a drilled hole in a pad or via.  For oval holes, the smaller (minor) diameter will be tested against the `min` value (if specified) and the larger (major) diameter will be tested against the `max` value (if specified).<br>                                                                                                                                                                                           |\n"
"| `hole_clearance`          | min                                                                                                                   | Checks the clearance between a drilled hole in a pad or via and copper objects on a different net.  The clearance is measured from the diameter of the hole, not its center.<br>                                                                                                                                                                                                                                                                       |\n"
"| `hole_to_hole`            | min                                                                                                                   | Checks the clearance between mechanically-drilled holes in pads and vias.  The clearance is measured between the diameters of the holes, not between their centers.<br><br>This constraint is soley for the protection of drill bits.  The clearance between **laser-drilled** (microvias) and other non-mechanically-drilled holes is not checked, nor is the clearance between **milled** (oval-shaped) and other non-mechanically-drilled holes.<br> |\n"
"| `physical_clearance`      | min                                                                                                                   | Checks the clearance between two objects on a given layer (including non-copper layers).<br><br>While this can perform more general-purpose checks than `clearance`, it is much slower.  Use `clearance` where possible.<br>                                                                                                                                                                                                                           |\n"
"| `physical_hole_clearance` | min                                                                                                                   | Checks the clearance between a drilled hole in a pad or via and another object, regardless of net. The clearance is measured from the diameter of the hole, not its center.<br><br>This can also be thought of as the \"drilling tolerance\" as it only includes **round** holes (see `edge_clearance` for the milling tolerance).<br>                                                                                                                   |\n"
"| `silk_clearance`          | min/opt/max                                                                                                           | Checks the clearance between objects on silkscreen layers and other objects.<br>                                                                                                                                                                                                                                                                                                                                                                       |\n"
"| `skew`                    | max                                                                                                                   | Checks the total skew for the nets that match the rule condition, that is, the difference between the length of each net and the average of all the lengths of each net that is matched by the rule.  If the absolute value of the difference between that average and the length of any one net is above the constraint `max` value, an error will be generated.<br>                                                                                  |\n"
"| `thermal_relief_gap`      | min                                                                                                                   | Specifies the width of the gap between a pad and a zone with a thermal-relief connection.<br>                                                                                                                                                                                                                                                                                                                                                          |\n"
"| `thermal_spoke_width`     | opt                                                                                                                   | Specifies the width of the spokes connecting a pad to a zone with a thermal-relief connection.<br>                                                                                                                                                                                                                                                                                                                                                     |\n"
"| `track_width`             | min/opt/max                                                                                                           | Checks the width of track and arc segments.  An error will be generated for each segment that has a width below the `min` value (if specified) or above the `max` value (if specified).<br>                                                                                                                                                                                                                                                            |\n"
"| `track_angle`             | min/opt/max                                                                                                           | Checks the angle between two connected track segments.  An error will be generated for each connected pair with an angle below the `min` value (if specified) or above the `max` value (if specified).<br>                                                                                                                                                                                                                                             |\n"
"| `track_segment_length`    | min/max                                                                                                               | Checks the length of track and arc segments.  An error will be generated for each segment that has a width below the `min` value (if specified) or above the `max` value (if specified).<br>                                                                                                                                                                                                                                                            |\n"
"| `via_count`               | max                                                                                                                   | Counts the number of vias on every net matched by the rule condition.  If that number exceeds the constraint `max` value on any matched net, an error will be generated for that net.<br>                                                                                                                                                                                                                                                              |\n"
"| `zone_connection`         | `solid`<br>`thermal_reliefs`<br>`none`                                                                                | Specifies the connection to be made between a zone and a pad.<br>                                                                                                                                                                                                                                                                                                                                                                                      |\n"
"\n"
"\n"
"" );