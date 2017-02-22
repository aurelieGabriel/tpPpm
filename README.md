[![Build Status](https://travis-ci.org/gatoravi/mpileup2readcounts.svg?branch=master)](https://travis-ci.org/gatoravi/mpileup2readcounts)
##Synopsis
Get the readcounts at a locus by piping samtools mpileup output.
This allows us to be flexible with the version of samtools used.
This program has been tested on samtools v1.3.1

##Install samtools 

##Compile mpileup2readcounts : 
```
g++ -std=c++11 -O3 mpileup2readcounts.cc -o mpileup2readcounts
```

##Usage

```
samtools mpileup -f ref.fa -l regions.bed BAM/*.bam | sed 's/		/	* 	*/g' | mpileup2readcounts 0 -5 false
```
Samtools arguments :
- FASTA file
- bed file
- BAM files : several samples can be parsed

Three options for mpileup2readcounts :
- 0 to parse all sample otherwise specify the number of the sample (for example 1 for the first sample)
- BQcut : base quality score cutoff for each mapped/unmapped base, only those larger than cutoff will be output in the result, to use no filter set BQcut to -5
- true to ignore indels 

##Example output
```
| chr |	loc	| ref	| depth	| A	| T	| C	| G	| a	| t	| c	| g	| Insertion	| Deletion	| depth	| A	| T	| C	| G	| a	| t	| c	| g	| Insertion	| Deletion	|
| 17 | 7572814	| C	| 25	| 0	| 0	| 23	| 0	| 0	| 0	| 2	| 0	| NA	| NA	| 8	| 0	| 0	| 8	| 0	| 0	| 0	| 0	| 0	| NA |	NA |
| 17	| 7572817	| C	| 28	| 0	| 0	| 26	| 0	| 0	| 0	| 2	| 0	| NA	| NA	| 8	| 0	| 0	| 8	| 0	| 0	| 0	| 0	| 0	| NA	| NA|
| 17	| 7579643	| C	| 48	| 0	| 0	| 9	| 0	| 0	| 0	| 39	| 0	| NA	| 4:ccccagccctccaggt|2:CCCCAGCCCTCCAGGT	| 9	| 0	| 0	| 6	| 0	| 0	| 0	| 3	| 0	| NA	| NA|
```

### Content of each line 
Common informations for all samples: 
- chromosome
- position on the chromosome
- reference base

For each sample :
- depth
- ATcg/atcg count
- insertions 
- deletions : in the example, there are 6 deletions found at position 7579643 for the first sample, 2 on the forward strand and 4 on the reverse strand

