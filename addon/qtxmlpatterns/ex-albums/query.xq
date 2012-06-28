<result>
{
 let $artists_doc := doc('artists.xml')
 let $albums_doc := doc('albums.xml')
 for $a in $albums_doc//albums/album,
     $s in $artists_doc//artists/artist
 where ends-with($s, 'Helloween')
     and $a/artistRef = $s/@id
 order by $a/year
 return  
   <album name='{$a/title}' year='{$a/year}'/>
}
 </result>