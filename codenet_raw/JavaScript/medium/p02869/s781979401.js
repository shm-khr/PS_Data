"use strict";
var GET=(function(){function f(s){return new g(s);}function g(s){this._s=s.trim().split("\n");this._y=0;}g.prototype.a=function(f){var s=this._s, y=this._y, r;if(typeof s[y]==="string")s[y]=s[y].split(" ").reverse();r=s[y].pop();if(!s[y].length)this._y++;return f?r:+r;};g.prototype.l=function(f){var s=this._s[this._y++].split(" ");return f?s:s.map(a=>+a);};g.prototype.m=function(n,f){var r=this._s.slice(this._y,this._y+=n).map(a=>a.split(" "));return f?r:r.map(a=>a.map(a=>+a));};g.prototype.r=function(n,f){var r=this._s.slice(this._y,this._y+=n);return f?r:r.map(a=>+a);};return f;})();
var o=GET(require("fs").readFileSync("/dev/stdin","utf8"));
function xArray(v){var a=arguments,l=a.length,r="Array(a["+--l+"]).fill(0).map(x=>{return "+v+";})";while(--l)r="Array(a["+l+"]).fill(0).map(x=>"+r+")";return eval(r);}

class mySet{
  constructor(){
    this.tree=[mySet.newChild(-1)];
    this.root=this.size=0,this.reuse=[];
  }

  add(x){
    var v=this.has(x);
    if(v>=0)return false;
    mySet.addmain(this,x,~v);
    return true;
  }
  static addmain(self,x,v){
    var tree=self.tree,p=tree[v].parent;
    tree[v].black=0,tree[v].value=x;
    self.size++;
    if(self.reuse.length){
      var l=self.reuse.pop(),r=self.reuse.pop();
      tree[v].left=l,tree[v].right=r;
      mySet.reset(tree,l);
      mySet.reset(tree,r);
      tree[l].parent=tree[r].parent=v;
    }else{
      var l=tree.push(mySet.newChild(v),mySet.newChild(v))-2;
      tree[v].left=l,tree[v].right=l+1;
    }
    if(p===-1)return tree[v].black=1;
    var V=v,P=p;
    while(P!==-1){
      if(tree[P].left===V)tree[P].lSize++;
      V=P,P=tree[P].parent;
    }
    while(tree[p].black===0){
      var pp=tree[p].parent,u;
      if(tree[pp].left===p)u=tree[pp].right;else u=tree[pp].left;
      if(tree[u].black){
        var ppp=tree[pp].parent;
        if(tree[pp].left===p)if(tree[p].left===v){
          var pr=tree[p].right;
          tree[p].right=pp,tree[p].parent=ppp,tree[p].black=1;
          tree[pp].left=pr,tree[pp].lSize-=tree[p].lSize+1,tree[pp].parent=p,tree[pp].black=0;
          tree[pr].parent=pp;
          if(ppp===-1)self.root=p;
          else if(tree[ppp].left===pp)tree[ppp].left=p;else tree[ppp].right=p;
        }else{
          var vl=tree[v].left,vr=tree[v].right;
          tree[v].left=p,tree[v].right=pp,tree[v].lSize+=tree[p].lSize+1,tree[v].parent=ppp,tree[v].black=1;
          tree[p].right=vl,tree[p].parent=v;
          tree[pp].left=vr,tree[pp].lSize-=tree[v].lSize+1,tree[pp].parent=v,tree[pp].black=0;
          tree[vl].parent=p,tree[vr].parent=pp;
          if(ppp===-1)self.root=v;
          else if(tree[ppp].left===pp)tree[ppp].left=v;else tree[ppp].right=v;
        }else if(tree[p].left===v){
          var vl=tree[v].left,vr=tree[v].right;
          tree[p].left=vr,tree[p].lSize-=tree[v].lSize+1,tree[p].parent=v;
          tree[v].left=pp,tree[v].right=p,tree[v].lSize+=tree[pp].lSize+1,tree[v].parent=ppp,tree[v].black=1;
          tree[pp].right=vl,tree[pp].parent=v,tree[pp].black=0;
          tree[vl].parent=pp,tree[vr].parent=p;
          if(ppp===-1)self.root=v;
          else if(tree[ppp].left===pp)tree[ppp].left=v;else tree[ppp].right=v;
        }else{
          var pl=tree[p].left;
          tree[p].left=pp,tree[p].lSize+=tree[pp].lSize+1,tree[p].parent=ppp,tree[p].black=1;
          tree[pp].right=pl,tree[pp].parent=p,tree[pp].black=0;
          tree[pl].parent=pp;
          if(ppp===-1)self.root=p;
          else if(tree[ppp].left===pp)tree[ppp].left=p;else tree[ppp].right=p;
        }
        break;
      }
      tree[p].black=tree[u].black=1,tree[pp].black=0;
      v=pp,p=tree[pp].parent;
      if(p===-1)return tree[v].black=1;
    }
  }

  delete(x){
    var v=this.has(x);
    if(v<0)return false;
    mySet.deletemain(this,v);
    return true;
  }
  static deletemain(self,v){
    var tree=self.tree,l=tree[v].left,r=tree[v].right;
    while(tree[l].left!==tree[r].left){
      if(tree[l].left!==-1){
        while(tree[l].right!==-1)l=tree[l].right;
        l=tree[l].parent;
        tree[v].value=tree[l].value;
        v=l;
      }else{
        while(tree[r].left!==-1)r=tree[r].left;
        r=tree[r].parent;
        tree[v].value=tree[r].value;
        v=r;
      }
      l=tree[v].left,r=tree[v].right;
    }
    self.size--;
    var p=tree[v].parent,V=v,P=p,b=tree[v].black;
    while(P!==-1){
      if(tree[P].left===V)tree[P].lSize--;
      V=P,P=tree[P].parent;
    }
    self.reuse.push(l,r);
    tree[v].value=undefined,tree[v].left=tree[v].right=-1,tree[v].lSize=0,tree[v].black=1;
    if(b===0||p===-1)return;
    if(tree[p].left===v)mySet.leftShortage(self,tree,v,p);
    else mySet.rightShortage(self,tree,v,p);
  }
  static leftShortage(self,tree,v,p){
    var s=tree[p].right,sl=tree[s].left,sr=tree[s].right,pp=tree[p].parent;
    if(tree[s].black===0){
      tree[p].right=sl,tree[p].parent=s,tree[p].black=0;
      tree[sl].parent=p;
      tree[s].left=p,tree[s].lSize+=tree[p].lSize+1,tree[s].parent=pp,tree[s].black=1;
      if(pp===-1)self.root=s;
      else if(tree[pp].left===p)tree[pp].left=s;else tree[pp].right=s;
      pp=s,s=sl,sl=tree[s].left,sr=tree[s].right;
    }
    if(tree[sr].black===0){
      tree[sl].parent=p,tree[sr].black=1;
      tree[s].left=p,tree[s].lSize+=tree[p].lSize+1,tree[s].parent=pp,tree[s].black=tree[p].black;
      tree[p].right=sl,tree[p].parent=s,tree[p].black=1;
      if(pp===-1)self.root=s,tree[s].black=1;
      else if(tree[pp].left===p)tree[pp].left=s;else tree[pp].right=s;
      return;
    }
    if(tree[sl].black===0){
      var sll=tree[sl].left,slr=tree[sl].right;
      tree[sll].parent=p,tree[slr].parent=s;
      tree[s].left=slr,tree[s].lSize-=tree[sl].lSize+1,tree[s].parent=sl;
      tree[sl].left=p,tree[sl].right=s,tree[sl].lSize+=tree[p].lSize+1,tree[sl].parent=pp,tree[sl].black=tree[p].black;
      tree[p].right=sll,tree[p].parent=sl,tree[p].black=1;
      if(pp===-1)self.root=sl,tree[sl].black=1;
      else if(tree[pp].left===p)tree[pp].left=sl;else tree[pp].right=sl;
      return;
    }
    tree[s].black=0;
    if(tree[p].black===0)return tree[p].black=1;
    if(pp===-1)return;
    if(tree[pp].left===p)mySet.leftShortage(self,tree,p,pp);
    else mySet.rightShortage(self,tree,p,pp);
  }
  static rightShortage(self,tree,v,p){
    var s=tree[p].left,sl=tree[s].left,sr=tree[s].right,pp=tree[p].parent;
    if(tree[s].black===0){
      tree[p].left=sr,tree[p].lSize-=tree[s].lSize+1,tree[p].parent=s,tree[p].black=0;
      tree[sr].parent=p;
      tree[s].right=p,tree[s].parent=pp,tree[s].black=1;
      if(pp===-1)self.root=s;
      else if(tree[pp].left===p)tree[pp].left=s;else tree[pp].right=s;
      pp=s,s=sr,sl=tree[s].left,sr=tree[s].right;
    }
    if(tree[sl].black===0){
      tree[sr].parent=p,tree[sl].black=1;
      tree[s].right=p,tree[s].parent=pp,tree[s].black=tree[p].black;
      tree[p].left=sr,tree[p].lSize-=tree[s].lSize+1,tree[p].parent=s,tree[p].black=1;
      if(pp===-1)self.root=s,tree[s].black=1;
      else if(tree[pp].left===p)tree[pp].left=s;else tree[pp].right=s;
      return;
    }
    if(tree[sr].black===0){
      var srl=tree[sr].left,srr=tree[sr].right;
      tree[srr].parent=p,tree[srl].parent=s;
      tree[s].right=srl,tree[s].parent=sr;
      tree[sr].left=s,tree[sr].right=p,tree[sr].lSize+=tree[s].lSize+1,tree[sr].parent=pp,tree[sr].black=tree[p].black;
      tree[p].left=srr,tree[p].parent=sr,tree[p].black=1;
      if(pp===-1)self.root=sr,tree[sr].black=1;
      else if(tree[pp].left===p)tree[pp].left=sr;else tree[pp].right=sr;
      return;
    }
    tree[s].black=0;
    if(tree[p].black===0)return tree[p].black=1;
    if(pp===-1)return;
    if(tree[pp].left===p)mySet.leftShortage(self,tree,p,pp);
    else mySet.rightShortage(self,tree,p,pp);
  }

  xor(x){
    var v=this.has(x);
    if(v<0){
      mySet.addmain(this,x,~v);
      return false;
    }
    mySet.deletemain(this,v);
    return true;
  }

  has(x){
    var v=this.root,tree=this.tree;
    while(tree[v].left!==-1){
      if(tree[v].value===x)return v;
      if(tree[v].value<x)v=tree[v].right;
      else v=tree[v].left;
    }
    return ~v;
  }

  lowerBound(x){
    var res=0,v=this.root,tree=this.tree,V=-1;
    while(tree[v].left!==-1){
      if(x<tree[v].value)V=v,v=tree[v].left;
      else if(x===tree[v].value)return [res+tree[v].lSize,v];
      else res+=tree[v].lSize+1,v=tree[v].right;
    }
    return [res,V];
  }
  upperBound(x){
    var res=0,v=this.root,tree=this.tree,V=-1;
    while(tree[v].left!==-1){
      if(x===tree[v].value){
        res+=tree[v].lSize+1,v=tree[tree[v].right].left;
        if(v===-1)return [res,V];
        while(tree[v].left!==-1)v=tree[v].left;
        return [res,tree[v].parent];
      }
      if(x<tree[v].value)V=v,v=tree[v].left;
      else res+=tree[v].lSize+1,v=tree[v].right;
    }
    return [res,V];
  }

  next(id){
    var tree=this.tree,c=tree[id].right;
    if(tree[c].left===-1){
      var p=tree[id].parent;
      while(p!==-1){
        if(tree[p].left===id)return p;
        id=p,p=tree[p].parent;
      }
      return -1;
    }else{
      while(tree[c].left!==-1)c=tree[c].left;
      return tree[c].parent;
    }
  }
  back(id){
    var tree=this.tree,c=tree[id].left;
    if(tree[c].left===-1){
      var p=tree[id].parent;
      while(p!==-1){
        if(tree[p].right===id)return p;
        id=p,p=tree[p].parent;
      }
      return -1;
    }else{
      while(tree[c].right!==-1)c=tree[c].right;
      return tree[c].parent;
    }
  }

  get first(){
    var v=this.root,tree=this.tree;
    while(tree[v].left!==-1)v=tree[v].left;
    return tree[v].parent;
  }
  get last(){
    var v=this.root,tree=this.tree;
    while(tree[v].right!==-1)v=tree[v].right;
    return tree[v].parent;
  }

  get show(){
    var v=[this.root],tree=this.tree;
    while(v.length){
      var v2=[],s=[];
      for(var i of v){
        if(tree[i].left===-1)s.push(-1);
        else{
        s.push(tree[i].value+(tree[i].black?"b":""));
        v2.push(tree[i].left,tree[i].right);
        }
      }
      console.log(s);
      v=v2;
    }
  }

  static newChild(p){return {value:undefined,left:-1,right:-1,lSize:0,parent:p,black:1};}
  static reset(tree,v){
    tree[v].value=undefined;
    tree[v].left=tree[v].right=-1;
    tree[v].lSize=0,tree[v].black=1;
  }
}

console.log(main());
function main(){
  var n = o.a();
  var k = o.a();
  var set1 = new mySet();
  var set2 = new mySet();
  for(var i = 0; i < n; i++){
    set1.add(k+i);
    set2.add(-k-n-i);
  }
  var ans = [];
  var l = k+n+n, r = l+n-1;
  while(l <= r){
    var c = r;
    var bid = set2.first;
    var b = -set2.tree[bid].value;
    mySet.deletemain(set2,bid);
    var aid = set1.upperBound(c-b)[1];
    if(aid === -1)aid = set1.last;
    else{
      aid = set1.back(aid);
      if(aid === -1)return -1;
    }
    var a = set1.tree[aid].value;
    mySet.deletemain(set1,aid);
    ans.push(a+" "+b+" "+c);
    r--;

    if(l > r)break;

    var c = l;
    var aid = set1.first;
    var a = set1.tree[aid].value;
    mySet.deletemain(set1,aid);
    var bid = set2.upperBound(a-c)[1];
    if(bid === -1)bid = set2.last;
    else{
      bid = set2.back(bid);
      if(bid === -1)return -1;
    }
    var b = -set2.tree[bid].value;
    mySet.deletemain(set2,bid);
    ans.push(a+" "+b+" "+c);
    l++;
  }
  return ans.join("\n");
}