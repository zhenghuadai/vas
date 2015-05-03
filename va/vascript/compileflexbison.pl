#!c:\perl\bin
use File::Copy; 

$vascript_0="vascript.y";

#check if it need to be compiled
$vaspasercpp_time=(stat "vasparser.cpp")[9];
$vascrpity_time=(stat $vascript_0)[9];
$vaslexercpp_time=(stat "vaslexer.cpp")[9];
$vascriptl_time=(stat "vascript.l")[9];

if (($vaspasercpp_time > $vascrpity_time) && ($vaslexercpp_time >$vascriptl_time )) {
	print "nothing to be done\n";
	exit 0;
}


#process vascript.y

$vascript="vascript.win.y";
open(outfile, ">$vascript");
open(infile, "$vascript_0");
$printswitch=0;
while($line=<infile>){
	if($printswitch==1){
		print outfile ($line);
	}else{
		if($line=~ "%header{"){
			print outfile ("%{\n");
			$printswitch=1;
		}
	}
};

$gnuDir="E:\\daizh\\GnuWin32\\bin\\";

`$gnuDir\\bison -d -ovasparser.cpp $vascript`;
`$gnuDir\\flex++ -+ -ovaslexer.cpp vascript.l`;



$vasparserheader="vasparser.h";
open(outf, ">$vasparserheader");
print outf ("#ifndef __VAS_PARSER_HEADER__\n");
print outf ("#define __VAS_PARSER_HEADER__\n"); 
print outf ("#include \"node.hxx\"\n");         
print outf ("#include \"vasparser.hpp\"\n");    
print outf ("#endif\n");                       
close(outf);

#process vaslexer.cpp
$dstf="vaslexer.cpp";
$tmpfile="vaslexerbk.cpp";
copy($dstf, $tmpfile);
open(outfile, ">$dstf");
open(infile, "$tmpfile") || die("can not open");
print outfile ("#include <iostream>\n");
print outfile ("using namespace std;\n");
while ($line=<infile>) {
	$line=~ s/class istream;//;
	print outfile ($line);
}
close(outfile);
close(infile);