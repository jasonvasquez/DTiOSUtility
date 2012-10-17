//
//  PBFetchedResultsBasedViewController.h
//  
//
//  Created by Jonathan Nolen on 10/4/12.
//
//
#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface DTFetchedResultsBasedViewController : UIViewController <NSFetchedResultsControllerDelegate>

@property (nonatomic, strong) NSFetchedResultsController *fetchedResultsController;

//Must implement this.
-(NSFetchedResultsController *)createFetchedResultsController;

//Override these to provide custom behavior.
-(void)cleanFetchedResultsControllerCache;
-(void)fetchResults;

//Implement these in child classes to handle the indicated events.
-(void)dataWillChange;
-(void)dataInsertedAtIndexPath:(NSIndexPath *)indexPath;
-(void)dataDeletedAtIndexPath:(NSIndexPath *)indexPath;
-(void)dataChangedAtIndexPath:(NSIndexPath *)indexPath;
-(void)dataMovedFromIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;
-(void)dataDidChange;

//Provide indirect access to underlying fetch request controller.
-(NSUInteger)numberOfSections;
-(NSUInteger)numberOfItemsInSection:(NSInteger)section;
-(id)objectAtIndexPath:(NSIndexPath *)indexPath;

@end
