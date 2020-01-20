//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008                                        //
//--------------------------------------------------------------------------//
/*
const static char *vertexShader=\
    "varying vec4 v;"
    "void main()"
    "{"
        "v=vec4(gl_Vertex.xy,64.0*gl_Color.xy);"
        "gl_Position=gl_Vertex;"
    "}";
*/

/*const static char *fragmentShader=
 "void main(){"
 "float f=dot(gl_Color.xyz,vec3(1,256,256*256))*0.005-4.0;"
 "f=mod(f,105.0);"
 "vec3 r=normalize(vec3(-7.0+0.01*gl_FragCoord.x,-5.0+0.01*gl_FragCoord.y,10.0));"
 "vec3 g=vec3(0,0,-10.0);"
"float u=200;"
"int c=0;"
"while(u>0.1&&c<200) {"
"vec3 p=g;"
"float e=3.0+sin(p.x+1.5)+p.y+cos(f)*2.5+sin(p.z+f*10.0);"
"float h=cosh(p.x)+sin(f)*sin(sin(p.y))+sin(p.z+f*15.0)+2.5+p.y;"
"float j=3.0+cos(p.x+1.5)+sinh(-p.x+1.5)+p.y+cos(f)+sin(p.z+f*15.0);"
"float k=cosh(p.x)-cosh(-p.x)+cosh(sin(p.y+sin(p.y)))+sin(p.z+f*30.0)+2.5+p.y;"
"p.z+=f*3.0;"
"p.x+=sin(f)*3.0+sin(p.z)*smoothstep(20.0,0.0,f);"
"p-=floor(p);"
"p-=0.5;"
"float i=max(max(abs(p.x),abs(p.y)),abs(p.z))-(sin(f/3.0+1.55)+1.0)/5.0*smoothstep(20.0,15.0,f);"
"float x=smoothstep(40.0,30.0,f);"
"float y=smoothstep(55.0,45.0,f);"
"float z=smoothstep(70.0,60.0,f);"
"float w=smoothstep(75.0,70.0,f);"
"float n=smoothstep(90.0,80.0,f);"
"float t=smoothstep(100.0,90.0,f);"
"u=i*x+e*(1.0-x)*y+h*(1.0-y)*z+j*(1.0-z)*n+i*(1.0-w)*t+(1.0-n)*k*t;"
"g=g+r*u;"
"c++;"
"}"
"gl_FragColor.rgb=vec3(0.4+smoothstep(70.0,95.0,f),smoothstep(30.0,40.0,f)*smoothstep(90.0,75.0,f),0.8*smoothstep(70.0,50.0,f))*c/75.0;"
"}"
; */


// float f=dot(gl_Color.xyz,vec3(1,256,256*256))*0.006;
//	vec3 r=normalize(vec3(7.0-0.01*gl_FragCoord.x,5.0-0.01*gl_FragCoord.y,10.0));

const static char *fragmentShader= "\
vec3 g;\
float m(float x, float y) {\
	x-=g.x;\
	y-=g.y;\
	float z = 15.0-g.z;\
	float r = (x*x+y*y+z*z)*1.5;\
	r=min(1.0,r);\
	return(2.0*r*r*r-3.0*r*r+1.0);\
}\
int dist_bw_rend(float z_r,float z_i,float c_r,float c_i,float stepsize)\
{\
	float z_r2=z_r*z_r,z_i2=z_i*z_i,dz_r=0,dz_i=0,tmp;\
	for(int iter=0;iter<60;iter++)\
	{\
		tmp=2*(z_r*dz_r-z_i*dz_i)+1;\
		dz_i=2*(z_r*dz_i+z_i*dz_r);\
		dz_r=tmp;\
		z_i=2*z_r*z_i+c_i;\
		z_r=z_r2-z_i2+c_r;\
		z_r2=z_r*z_r;\
		z_i2=z_i*z_i;\
		if(z_r2+z_i2>4)\
		{\
			float z2=z_r*z_r+z_i*z_i;\
			float dz=sqrt(dz_r*dz_r+dz_i*dz_i);\
			float dist=log(z2)*sqrt(z2)/dz;\
			if(dist<stepsize)\
			{\
				int c=int(dist/stepsize*256);\
				return(c);\
			}\
			else return(255);\
		}\
	}\
	return(255);\
}\
void main(){\
	float f=dot(gl_Color.xyz,vec3(1,256,256*256))*0.0046;\
	vec3 r=normalize(vec3(7.0-0.01*gl_FragCoord.x,5.0-0.01*gl_FragCoord.y,10.0));\
	g=vec3(0,0,0);\
	float u=200;\
	int c=0;\
	float ball;\
	float bs;\
	float blb; \
	float bbar;\
	float bv;\
	float ba;\
	float bt;\
	float bg;\
	float balls;\
	float cubefield;\
	float tori;\
	float tori2;\
	float blobs;\
	while(u>0.01&&c<150){\
		vec3 p=g;\
		float sinescape = 3.0+sin(p.x+1.5)-p.y+sin(p.z-f*50.0);\
		float sinescape2 = min(sinescape, 3.0+sin(p.x+1.5)+p.y+sin(p.z-f*50.0));\
		float small = 0.0000001;\
		float sunrise = cosh(p.x) * small*small*small*small + sinescape;\
		ball = abs((p.x*p.x+p.y*p.y)-0.1);\
		vec3 e;\
		vec3 d;\
		p.z+=f*3.0;\
		e = p;\
		d = p;\
		e.x -= 0.5;\
		e.y -= 0.5;\
		d.y -= 0.5;\
		p -= floor(p);\
		e -= floor(e);\
		d -= floor(d);\
		p -= 0.5;\
		e -= 0.5;\
		d -= 0.5;\
		balls = abs((p.x*p.x+p.y*p.y+p.z*p.z)-0.1);\
		cubefield = max(max(abs(p.x),abs(p.y)),abs(p.z)) - 0.2;\
		tori = length(vec2(length(e.xy)-0.3,e.z))-0.05;\
		tori2 = length(vec2(length(d.xz)-0.3,d.y))-0.05;\
		float t = cos(f) * p.z + sin(f)*0.2;\
		p.x = p.x * cos(t) - p.y * sin(t);\
		p.y = p.x * sin(t) - p.y * cos(t);\
		float balls2 = abs((p.x*p.x+p.y*p.y+p.z*p.z)-0.1);\
		float twistfield = max(max(abs(p.x),abs(p.y)),abs(p.z)) - 0.2;\
		float start = (balls+ball)/(20.0+smoothstep(10.0,0.0,f)*50.0);\
		float qfield = (balls2+twistfield)/2.0;\
		if( f < 40.0 ) {\
			u = start * smoothstep(15.0,3.0,f)  * smoothstep(10.1,10.0,f)+ \
				balls * smoothstep(10.0,18.0,f) * smoothstep(22.0,19.0,f)+ \
				balls2 * smoothstep(20.0,23.0,f) * smoothstep(28.1,28.0,f) +\
				cubefield * smoothstep(28.0,28.1,f) * smoothstep(40.0,37.0,f) +\
				twistfield * smoothstep(38.0,41.0,f) * smoothstep(45.0,43.0,f);\
		} else if( f < 80.0 ) {\
			u = twistfield * smoothstep(38.0,41.0,f) * smoothstep(44.3,44.0,f) +\
				sunrise * smoothstep(44.0,45.0,f) * smoothstep(50.0,43.0,f) + \
				sinescape * smoothstep(44.0,45.0,f) * smoothstep(48.0,46.0,f) +\
				(balls+ball)/40.0 * smoothstep(48.0,49.0,f)*smoothstep(54.0,52.0,f) + \
				(balls+ball)/40.0 * smoothstep(60.4,60.45,f)*smoothstep(65.1,65.0,f) +\
				qfield * smoothstep(61.0,62.1,f) * smoothstep(65.0,64.0,f) +\
				cubefield * smoothstep(64.0,66.0,f) * smoothstep(71.0,70.0,f) +\
				cubefield * smoothstep(70.0,71.0,f) * smoothstep(76.0,75.0,f) +\
				min(tori2,tori) * smoothstep(75.0,76.0,f) * smoothstep(85.0,84.0,f);\
		} else {\
			blobs = 0.5;\
			for( int i = 0; i < 5; i++ ) {\
				vec3 d = vec3(sin(f*2.0*cos(i*1243342.0)+i*20000.0),cos(i*200321.0)+sin(f*3.0+cos(i*20321.0)),10.0+sin(i*31233.0)*4.0)-g;\
				float r = (d.x*d.x+d.y*d.y+d.z*d.z)*1.5;\
				r=min(1.0,r);\
				blobs-=(2.0*r*r*r-3.0*r*r+1.0);\
			}\
			float b1 = m(0.0,-1.5);\
			bs = 0.5	-m(1.0,-1.5)\
						-b1\
						-m(1.5,-0.5)\
						-m(0.5,0.0)\
						-m(-0.5,0.5)\
						-m(0.0,1.5)\
						-m(1.0,1.5);\
			blb = 0.5 -m(1.0,-1.5)\
						-m(1.0,-0.5)\
						-m(1.0,0.5);\
			bbar = blb-m(-1.0,-1.5)\
						-m(-1.0,-0.5)\
						-m(-1.0,0.5);\
			bv = bbar -m(0.0,1.0);\
			ba = bbar -b1\
						-m(0.0,-0.2)\
						+0.2;\
			bt = 0.5 	-b1\
				  		-m(0.0,-0.5)\
				 		-m(0.0,0.5)\
						-m(-1.0,-1.5)\
						-m(1.0,-1.5);\
			bg = blb	-b1\
						-m(0.0,1.0)\
						-m(-1.0,0.5)*0.6\
						-m(-0.3,-0.2)*0.6;\
			u = min(tori2,tori) * smoothstep(77.0,78.0,f) * smoothstep(85.0,84.0,f) +\
				min(sinescape2, blobs) * smoothstep(84.0,85.0,f) * smoothstep(89.0,88.0,f) +\
				min(sinescape2, bs) * smoothstep(88.0,89.0,f) * smoothstep(91.0,90.0,f) +\
				min(sinescape2, bv) * smoothstep(90.0,91.0,f) * smoothstep(93.0,92.0,f) +\
				min(sinescape2, ba) * smoothstep(92.0,93.0,f) * smoothstep(95.0,94.0,f) +\
				min(sinescape2, bt) * smoothstep(94.0,95.0,f) * smoothstep(97.0,96.0,f) +\
				min(sinescape2, bg) * smoothstep(96.0,97.0,f) * smoothstep(99.0,98.0,f);\
		}\
		g.x+=g.z*0.0003*smoothstep(50.0,51.0,f)*smoothstep(55.0,54.0,f);\
		g.y-=g.x*0.005*smoothstep(50.0,51.0,f)*smoothstep(56.0,55.0,f);\
		g.x+=p.y*0.001*smoothstep(52.0,54.0,f)*smoothstep(67.0,66.0,f);\
		g.y+=p.x*0.001*smoothstep(53.0,55.0,f)*smoothstep(67.0,66.0,f);\
		g.x+=p.y*0.01*smoothstep(61.0,67.1,f)*smoothstep(70.0,69.0,f);\
		g.y+=p.x*0.01*smoothstep(61.0,67.1,f)*smoothstep(70.0,69.0,f);\
		g.x-=p.y*0.01*smoothstep(70.0,70.1,f)*smoothstep(75.0,74.0,f);\
		g.y-=p.x*0.01*smoothstep(70.0,70.1,f)*smoothstep(75.0,74.0,f);\
		g=g+r*u;\
		c++;\
	}\
	float h = f - 55.0;\
	float xm = 0.398;\
	if( f > 70 ) {\
		h = f - 81.0;\
		xm = 0.399;\
	}\
	r.z=1.0;\
	float zr = (r/pow(9.3,h)).x+xm;\
	float zi = (r/pow(9.3,h)).y+0.199;\
	float fr = dist_bw_rend(zr,zi,zr,zi,(r/pow(9.8,h)).z);\
	c+=int(fr*smoothstep(52.0,52.9,f)*smoothstep(61.0,60.0,f));\
	c+=int(fr*smoothstep(80.0,83.0,f)*smoothstep(84.0,81.0,f));\
	gl_FragColor.rgb=(\
					vec3(0.6,0.0,0.1)*smoothstep(0.0,1.0,f)*smoothstep(33.0,29.0,f) +\
					vec3(0.0,0.0,0.7)*ball*smoothstep(0.0,1.0,f)*smoothstep(41.0,40.0,f)+\
					vec3(0.0,0.6,0.1)*smoothstep(29.0,33.0,f)*smoothstep(44.0,43.0,f)+\
					vec3(1.0,1.0,1.0)*smoothstep(43.0,44.0,f)*smoothstep(49.0,48.0,f)+\
					vec3(0.6,0.9,0.3)*smoothstep(48.0,49.0,f)*smoothstep(62.0,61.0,f)+\
					vec3(0.5,0.0,0.1)*smoothstep(61.0,62.0,f)*smoothstep(66.0,64.0,f)+\
					vec3(0.1,0.0,0.4)*smoothstep(64.0,66.0,f)*smoothstep(78.0,77.0,f)+\
					vec3(0.0,0.0,0.1)*ball*smoothstep(64.0,66.0,f)*smoothstep(85.0,84.0,f)+\
					vec3(1.0,0.5,0.0)*smoothstep(77.0,78.0,f)\
	)*c/(75.0);\
}"
;