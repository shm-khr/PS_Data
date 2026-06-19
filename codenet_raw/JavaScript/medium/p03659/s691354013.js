function main( input ){

  var as = input.split( /\n/ )[1]
                .split( /\s/ )
                .map( function( n ){
                  return parseInt( n )
                } )

  var r = 0
  for( var i=1; i<as.length; i++ )
    r += as[i]

  var m = Math.abs( r - as[0] )

  function min( as, position, l, r ){
    if( as.length - 1 <= position )
      return

    l += as[position]
    r -= as[position]

    if( m > Math.abs( l - r ) )
      m = Math.abs( l - r )

    min( as, position + 1, l, r )
  }

  min( as, 1, as[0], r )

  console.log( m )

}

main(
  require( 'fs' )
    .readFileSync( '/dev/stdin', 'utf8' )
)
